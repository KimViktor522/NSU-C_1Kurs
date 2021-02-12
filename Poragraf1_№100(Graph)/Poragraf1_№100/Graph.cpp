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

//создание вектора для ребер
void creatMasN_2(mas& array, int N) {
	array.resize(N);
	for (int i{}; i < N; ++i) {
		array[i].resize(2);
	}
}

//вывод матрицы смежности
void printMasN_N(mas& array, int N) {
	printf("\t");
	for (int i{}; i < N; ++i) {
		printf("%d:\t", i + 1);
	}
	printf("\n");
	for (int i{}; i < N; ++i) {
		printf("%d:\t",i+1);
		for (int j{}; j < N; ++j) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//вывод ребер
void printMasN_2(mas& array, int N) {
	for (int i{}; i < N; ++i) {
		printf("%d:\t", i+1);
		for (int j{}; j < 2; ++j) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//ввод ребер (1-не корректный ввод, 0-все ок)
int inputValunInMasN_2(mas& array, int N) {
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
void build_mas_Graph(mas& array, mas& ribs, int N) {
	for (int i{}; i < N; ++i) {
		array[ribs[i][0]-1][ribs[i][1]-1] = 1;
	}
}

//окраска дуги принадлежащей только одному пути длины не более int_Color_Ribs
void painting_arc(mas& array, int top_1, int top_2, int int_Color_Ribs) {

}

int main() {
	system("chcp 65001"); system("cls");
	int N{}, R{}, check{};//N-количество вершин, R-количество ребер
	mas mas_Ribs{};  //массив с ребрами
	printf("1 - ввести вручную ребера, 0 - взять готовые ребра\n");
	scanf("%d",&check);
	if (check) { //ввод вручную
		printf("Введите количество венршин и ребер:");
		scanf("%d %d", &N, &R);
		creatMasN_2(mas_Ribs, R);
		printf("\nВершины в виде чисел 1-%d \n Введите пары \n Пример ввода: 1 2 - это ребро из 1 вершины во 2 \n",N);
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
	mas mas_Graph{}; creatMasN_N(mas_Graph, N); //матрица смежности
	printMasN_2(mas_Ribs, R);
	build_mas_Graph(mas_Graph, mas_Ribs, R);
	printMasN_N(mas_Graph, N);

	int top_1{}, top_2{}, int_Color_Ribs{};
	printf("Введите две вершины и максимальное количество цветных дуг:\n");
	scanf("%d %d %d", top_1, top_2, int_Color_Ribs);
	painting_arc(mas_Graph, top_1, top_2, int_Color_Ribs)
	return 0;
}