//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
//на ввод "ABCDEFGI21457."
#include <stdio.h>
#include <stdlib.h>

int permutation(int &i) {
	while (i != -1) {//пока не встретели '.'
		char x;
		++i;
		scanf("%c", &x);
		if (x != '.') {
			if (i != 5) permutation(i);
			printf("%c", x);
			if (i == -1) return i;//дошли до точки
			if (i != 1) return --i;//для того чтобы при выводе первой из пяти буквы не вышли из рекурсии
			--i;
		}
		else return i=-1;
	}
	return 0;
}


int main() {
	system("chcp 65001"); system("cls");
	int i{};
	printf("Введите строку с точкой в конце: ");
	permutation(i);
	printf("\n");
	return 0;
}