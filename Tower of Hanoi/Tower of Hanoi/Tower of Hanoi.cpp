//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//количество колец на башнях
void num_Of_Rings(int** mas, int* ringNum, int N) {
	for (int i{}; i < 3; ++i) {
		for (int j{}; j < N; ++j) {
			if (mas[i][j] == 1) ++ringNum[i];
		}
	}
}

//находит размер кольца которое нужно нарисовать
int ring_size(int **mas, int* oldRingSize, int numTower, int N) {
	for (int i{ oldRingSize[numTower] }; i < N; ++i) {
		if (mas[numTower][i] == 1) return i+1;
	}
	return 0;
}

//номер верхнего кольца на башне
int search_free_ring(int** mas, int tower, int N) {
	for (int i{}; i < N; ++i) {
		if (mas[tower][i] == 1) return i;
	}
	return 0;
}

//вывод 3-х башен
void print(int** mas, int N) {
	int num{ ((N + 1) * 2 + 1) };//1*2 это столбцы по бокам; и один это стержень башни
	int ringNum[3]{}, ringSize[3]{};
	num_Of_Rings(mas, ringNum, N);
	for (int i{}; i < N + 2; ++i) {//первая строка это сам башня; вторая это основание
		for (int k{ 1 }; k <= 3; ++k) {//3 башни
			if (i > N - ringNum[k - 1]) //если в башне k есть кольца на i строку
				ringSize[k-1] = ring_size(mas, ringSize, k-1, N);
			for (int j{}; j < num; ++j) {
				if (i == N + 1) {//основание 
					if (j == (N + 1)) printf("%c", (char)202);//202 ~ ╩
					else if (j == 0) printf("%c", (char)212);//212 ~ └
					else if (j == num-1) printf("%c", (char)190);//190 ~ ┘
					else printf("%c", (char)205);//205 ~ ═
				}
				else if (j == (N + 1)) printf("%c", (char)186);//186 ~ ║
				else if ((i > N - ringNum[k - 1]) && j > (N - ringSize[k - 1]) && (j < (num - 1 - N + ringSize[k - 1]))) printf("%c", (char)219);//219 ~ █
				else printf("%c", (char)255);//255 ~  
			}
		}
		printf("\n");
	}
}

//перестановка колец
void  perm_Tower(int **mas, int value, int start, int buffer, int end, int &numOfMove, int N) {
	if (value == 0) return;
	perm_Tower(mas, value - 1, start, end, buffer, numOfMove, N);
	int num{ search_free_ring(mas, start, N) };
	mas[start][num] = 0;
	mas[end][num] = 1;
	printf("%d -- > %d\n", start + 1, end + 1);
	print(mas, N);
	++numOfMove;
	for (int i{}; i < 50000000; ++i);
	perm_Tower(mas, value - 1, buffer, start, end, numOfMove, N);
	return;
}


int main() {
	int N;
	printf("N = "); //("Введите количество колец: ");
	scanf("%d", &N);
	int** mas = new int* [3];//создаю двумерный массив 3*N - 3 башни по N колец
	for (int i{}; i < 3; ++i) {
		mas[i] = new int[N];
	}
	for (int j{}; j < N; ++j) {//заполняем 1 башню
		mas[0][j] = 1;
	}
	print(mas, N);
	int start{ 0 }, buffer{ 1 }, end{ 2 }, value{ N }, numOfMove{};
	perm_Tower(mas, value, start, buffer, end, numOfMove, N);
	printf("Number of moves - %d", numOfMove);
	return 0;
}