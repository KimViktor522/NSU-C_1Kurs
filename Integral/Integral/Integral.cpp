//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float Integral(float x, float dx) {
	return ((x * dx) / ((x * x + 1) * (x * x + 1)));
}

int main() {
	system("chcp 65001"); system("cls");
	const int N{ 20 };
	float x_start{ -1 }, x_end{ 2 }, xd{ (x_end - x_start) / N }, S{};
	for (int i{ 0 }; i < N; ++i) {
		S += Integral(x_start += (xd / 2), xd);
		x_start += xd;
	}
	printf("%f\n",S);
	return 0;
}