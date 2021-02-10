//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using mas = vector<vector<int>>;

//создание вектора
void creatMasN_N(mas& array, int N) {
	array.resize(N);
	for (int i{}; i < N; ++i) {
		array[i].resize(N);
	}
}

//создание вектора для таблицы приоритов
void creatMasN_2(mas& array, int N) {
	array.resize(N);
	for (int i{}; i < N; ++i) {
		array[i].resize(2);
	}
}

//вывод приоритетов мущин или женцин
void printMas(mas& array, int N) {
	for (int i{}; i < N; ++i) {
		printf("%d:",i);
		for (int j{}; j < N; ++j) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//заполнение приоритетов мущин или женцин
void inputValunInMasN_2(mas& array, int N) {
	for (int i{}; i < N; ++i) {
		for (int j{}; j < 2; ++j) {
			
		}
	}
}


int main() {
	system("chcp 65001"); system("cls");
	int N{}, R{};//N-количество вершин, R-количество ребер
	bool check{};
	printf("Введите количество венршин и ребкр:");
	scanf("%d %d", &N, &R);
	mas mas_Graph_Input{}; creatMasN_2(mas_Graph_Input, N); //массив с ребрами
	mas mas_Graph{}; creatMasN_N(mas_Graph, N);	//матрица смежности
	printf("1 - ввести вручную ребера, 0 - взять готовые ребра");
	scanf("%b",check);
	if (check) {
		inputValunInMas(mas_Graph_Input, N);
	}
	else {
		mas_Graph_Input = {
			{};
			{};
			{};
		};
	}
	scanf();
	return 0;
}