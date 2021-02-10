//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	system("chcp 65001"); system("cls");
	int minute{}, hours{};
	printf("Ввидите часы и минуты: ");
	scanf("%d %d", &hours, &minute);
	if (minute > 60 || minute < 0 || hours>12 || hours < 0) {//проверка ввода
		printf("Некорректный ввод!");
		return 0;
	}
	hours = hours * 5 + (minute / 12);//перевод часовой стрелки на минутные деления
	int new_hours_min{ hours }, int_minute{};

	while (new_hours_min != minute){
		++int_minute;
		++minute;
		if (minute == 60) {
			minute = 0;
			++int_minute;
			++new_hours_min;
		}
		else if ((minute) / 12 > (minute - 1) / 12) ++new_hours_min;
		if (new_hours_min == 59 && minute == 59) {
			++int_minute;
			break;
		}
	}
	printf("Через %d мин стрелки совпадут", int_minute);
	return 0;
}