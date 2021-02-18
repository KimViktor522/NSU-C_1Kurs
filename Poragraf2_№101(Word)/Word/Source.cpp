//Проект > Свойства проекта > C/C++ > Препроцессор > Определение препроцессора > Изменить... > _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

//Вывод строки 
void str_print(string& print, int N) {
    for (int i{}; i < N; ++i) {
        printf("%c", print[i]);
    }
    printf("\n");
}

int main() {
    system("chcp 65001"); system("cls");
    int N{};
    string print{};
    printf("Введите максимальную длину цепочки: ");
    scanf("%d", &N);
    printf("\n");
    if (N % 2 == 0) N = ((N - 1) / 2) * 3 + 2;
    else N = (N / 2) * 3 + 1;
    for (int i{}; i < N; ++i) {
        print.resize(i + 1, 'A'); //Изменяет размер длины строки на i и заполняет символом A
        for (int j{}; j < pow(2, i + 1); ++j) { //переберает все возможные варианты длины i
            if (print.find("AAA") == string::npos && print.find("BBB") == string::npos) {
                str_print(print, i + 1);
            }
            if (print[0] == 'A') {
                print[0] = 'B';
            }
            else for (int k{}; k < i; ++k) {
                if (print[k] == 'B') {
                    print[k] = 'A';
                }
                if (print[k + 1] == 'A') {
                    print[k + 1] = 'B';
                    break;
                }
            }
        }
        print.clear();
    }
    return 0;
}