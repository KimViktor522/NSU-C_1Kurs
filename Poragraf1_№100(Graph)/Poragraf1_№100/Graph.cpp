//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using masN_N = vector<vector<int>>;
using masN = vector<int>;

//создание вектора (массива) N*N
void creatMasN_N(masN_N& array, int N) {
	array.resize(N);
	for (int i{}; i < N; ++i) {
		array[i].resize(N);
	}
}

//создание вектора (массива) N*2  //для ребер
void creatMasN_2(masN_N& array, int N) {
	array.resize(N);
	for (int i{}; i < N; ++i) {
		array[i].resize(2);
	}
}

//создание вектора (массива) N
void creatMasN(masN& array, int N) {
	array.resize(N);
}

//вывод вектора (массива) N*N //матрицы смежности
void printMasN_N(masN_N& array, int N) {
	printf("\t");
	for (int i{}; i < N; ++i) {
		printf("%d:\t", i + 1);
	}
	printf("\n");
	for (int i{}; i < N; ++i) {
		printf("%d:\t", i + 1);
		for (int j{}; j < N; ++j) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//вывод вектора (массива) N*2 //ребер
void printMasN_2(masN_N& array, int N) {
	for (int i{}; i < N; ++i) {
		printf("%d:\t", i + 1);
		for (int j{}; j < 2; ++j) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//вывод вектора (массива) N //ребер
void printMasN(masN& array, int N) {
	printf("\t");
	for (int i{}; i < N; ++i) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}

//ввод ребер (1-не корректный ввод, 0-все ок)
int inputValunInMasN_2(masN_N& array, int N) {
	for (int i{}; i < N; ++i) {
		for (int j{}; j < 2; ++j) {
			scanf("%d", &array[i][j]);
			if (array[i][j] > N || array[i][j] <= 0) {
				printf("Не корректный ввод вершины %d\n", array[i][j]);
				return 1;
			}
		}
	}
	return 0;
}

//постоение матрицы смежности
void build_mas_Graph(masN_N& array, masN_N& ribs, int N) {
	for (int i{}; i < N; ++i) {
		array[ribs[i][0] - 1][ribs[i][1] - 1] = 1;
	}
}

//число не провереных ребер
int clear_Ribs(masN_N& mas_Graph, int top_1, int N) {
	int num{};
	for (int i{}; i < N; ++i) {
		if (mas_Graph[top_1][i] == 1) ++num;
	}
	return num;
}

//окраска дуги принадлежащей только одному пути длины не более int_Color_Ribs
int painting_arc(masN_N& mas_Graph, masN used_Tops, int top_1, int top_2, int& int_Color_Ribs, int N) {
	printMasN_N(mas_Graph, N);
	printMasN(used_Tops, N);
	printf("%d\n", top_1);
	bool check{}; //проверяет прошли ли top_2
	++used_Tops[top_1 - 1]; //обошли эту вершину
	for (int j{}; j < N; ++j) {
		if (mas_Graph[top_1 - 1][j] == 1) { //существует дуга из top_1  в j. И  это точки небыло рание
			if (j == top_2 - 1) {//дошли до top_2 
				++mas_Graph[top_1 - 1][j];
				--int_Color_Ribs;
				check = true;
				//return 1;
			}
			if ((used_Tops[j] < 2) && painting_arc(mas_Graph, used_Tops, j + 1, top_2, int_Color_Ribs, N) == 1) {
				--int_Color_Ribs;
				if (mas_Graph[top_1 - 1][j] == 1) ++mas_Graph[top_1 - 1][j];
			}
			else {
				if (mas_Graph[top_1 - 1][j] == 1) {
					++++mas_Graph[top_1 - 1][j];
					if (clear_Ribs(mas_Graph, j, N) == 1) return 0;
				}
			}
		}
		else if (mas_Graph[top_1 - 1][j] == 2) {//снимаем цвет т.к. встречали этот путь
			if (j == top_2 - 1) {//дошли до top_2 
				++mas_Graph[top_1 - 1][j];
				++int_Color_Ribs;
				--used_Tops[top_1 - 1];
				check = true;
				//return 1;
			}
			if (painting_arc(mas_Graph, used_Tops, j + 1, top_2, int_Color_Ribs, N)) {
				if (mas_Graph[top_1 - 1][j] == 2) ++mas_Graph[top_1 - 1][j];
				++int_Color_Ribs;
				--used_Tops[top_1 - 1];
			}
		}
	}
	if (check) return 1;
	else return 0;
}

int main() {
	system("chcp 65001"); system("cls");
	int N{}, R{}, check{};//N-количество вершин, R-количество ребер
	masN_N mas_Ribs{};  //массив с ребрами
	printf("1 - ввести вручную, 0 - взять все готовое\n");
	scanf("%d", &check);
	if (check) { //ввод вручную
		printf("Введите количество венршин и ребер:");
		scanf("%d %d", &N, &R);
		creatMasN_2(mas_Ribs, R);
		printf("\nВершины в виде чисел 1-%d \n Введите пары \n Пример ввода: 1 2 - это ребро из 1 вершины во 2 \n\n", N);
		if (inputValunInMasN_2(mas_Ribs, N)) return 0;//
	}
	else {//готовый (заданый) граф
		N = 7;
		R = 12;
		creatMasN_2(mas_Ribs, R);
		mas_Ribs = {
			{1,2},
			{1,3},
			{1,4},
			{2,4},
			{2,6},
			{3,7},
			{4,3},
			{4,7},
			{5,1},
			{6,5},
			{6,7},
			{7,5}
		};
	}
	masN_N mas_Graph{}; creatMasN_N(mas_Graph, N); //матрица смежности
	masN used_Tops{}; creatMasN(used_Tops, N); //вершины которые уже обошли
	printMasN_2(mas_Ribs, R);
	build_mas_Graph(mas_Graph, mas_Ribs, R);
	printMasN_N(mas_Graph, N);

	int top_1{}, top_2{}, int_Color_Ribs{};
	if (check) {
		printf("Введите две вершины и максимальное количество цветных дуг:\n");
		scanf("%d %d %d", top_1, top_2, int_Color_Ribs);
	}
	else {
		top_1 = 2;
		top_2 = 7;
		int_Color_Ribs = 4;
		printf("top_1 = %d\ntop_2 = %d\nint_Color_Ribs = %d\n", top_1, top_2, int_Color_Ribs);
	}
	painting_arc(mas_Graph, used_Tops, top_1, top_2, int_Color_Ribs, N);//обход от top_1 до top_2
	//painting_arc(mas_Graph, used_Tops, top_2, top_1, int_Color_Ribs, N);//обход от top_1 до top_2

	printMasN_N(mas_Graph, N);

	printf("top_1 = %d\ntop_2 = %d\nint_Color_Ribs = %d\n", top_1, top_2, int_Color_Ribs);
	return 0;
}