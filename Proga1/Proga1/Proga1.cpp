#include <stdio.h>
#define N 4

int main() {
	int x[N], y[N];
	for (int i = 0; i < N; ++i) {
		printf("Введите координаты %d точки\n", i);
		scanf("%d %d", &x[i], &y[i]);
	}
	printf("z = %d", x[1]);

	return 0;
}