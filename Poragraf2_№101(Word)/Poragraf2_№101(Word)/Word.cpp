//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	system("chcp 65001"); system("cls");
	int N{3};
	string print{};
	printf("Введите максимальную длину цепочки: ");
	//scanf("%d", N);
	printf("\n");
	for (int i{}; i < N; ++i) {
		print.resize(i+1, 'A'); //Изменяет размер длины строки на i и заполняет символом A
		for (int j{}; j < pow(2,i); ++j) { //переберает все возможные варианты длины i
			if (print.find("AAA") == string::npos && print.find("BBB") == string::npos) {
				printf("%c\n", print);
			}
			if (print[0] == 'A') {
				print[0] = 'B';
			}
			else for (int k{1}; k < i + 1; ++k) {
				if (print[k] != 'B') {
					print[k] = 'A';
				}
			}
		}
	}
	return 0;
}