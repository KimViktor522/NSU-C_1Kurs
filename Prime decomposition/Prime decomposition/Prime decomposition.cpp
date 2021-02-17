//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

//проверка является ли число простым
bool prime(int p) {
	for (int i{2}; i <= sqrt(p); ++i) {
		if (p%i == 0) return false;
	}
	return true;
}

int main() {
	system("chcp 65001"); system("cls");
	int N{}, p_1{2};
	printf("Введите целое четное число: ");
	scanf("%d", &N);
	while (!prime(p_1) || !prime(N-p_1)) {
		++p_1; 
	}
	printf("\n%d = %d + %d\n", N, p_1, N - p_1);
	return 0;
}