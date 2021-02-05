#include <stdio.h>
#include <stdlib.h>
#define N 4

int main() {
    system("chcp 65001"); system("cls");
    float xy[N][2]; //xy[i][0] - координата x
                  //xy[i][1] - координата y
    float vec_Side[N - 1][2]; //вектора боковой стороны 
    float vec_Top[N - 1][2]; //вектора из вершины к точке
    float comp_Vec[N - 1]; //произведение векторов
    int check{}; //0 - положительное значение
                 //1 - отрицательное значение 
                 //2 - точка лежит на боковой стороне
                 //-1 - точка лежит вне треуголние 
    printf("Введите 4 точки для проверки лежит ли точка 4 в треугольнике из первых 3 точек!\n\n");
    for (int i = 0; i < N; ++i) { //ввод коодинат 4-х точек
        printf("Введите координаты %d точки: ", i + 1);
        for (int j = 0; j < 2; ++j) {
            scanf("%f", &xy[i][j]);
        }
    }
    for (int i = 0; i < N - 1; ++i) { 
        for (int j = 0; j < 2; ++j) {
            vec_Side[i][j] = xy[i + 1][j] - xy[i][j]; //вычисление векторов
            vec_Top[i][j] = xy[3][j] - xy[i][j];
        }
        comp_Vec[i] = vec_Side[i][0] * vec_Top[i][1] - vec_Side[i][1] * vec_Top[i][0]; //вычисление произведения векторов
    }
    if (comp_Vec[0] < 0) check = 1; //проверка ориентации векторов
    else if (comp_Vec[0] == 0) check = 2;
    for (int i = 0; i < N - 1; ++i) { 
        if ((comp_Vec[i] < 0 && (check == 1 || check == 2)) || (comp_Vec[i] > 0 && (check == 0 || check == 2))) continue;
        else if (comp_Vec[i] == 0) check = 2;
        else {
            check = -1;
            break;
        }
    }
    if (check == 0 || check == 1) printf("Точка лежит внутри треугольника\n");
    else if (check == 2) printf("Точка лежит на боковой стороне треугольника\n");
    else printf("Точка лежит вне треугольника\n");

    return 0;
} 