#include <stdio.h>

int main(void)
{
	int Ax, Ay, Bx, By, Cx, Cy;
	float AB, AC, BC;
	printf("Введите координаты x, y первой вершины:\n");
	scanf("%d %d", &Ax, &Ay);
	printf("Введите координаты x, y второй вершины:\n");
	scanf("%d %d", &Bx, &By);
	printf("Введите координаты x, y третей вершины:\n");
	scanf("%d %d", &Cx, &Cy);
	AB= (Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By);
	AC= (Ax-Cx)*(Ax-Cx)+(Ay-Cy)*(Ay-Cy);
	BC= (Bx-Cx)*(Bx-Cx)+(By-Cy)*(By-Cy);
	printf("%g %g %g\n",AB,AC,BC );
	if (AB == AC+BC || BC == AC+AB || AC == BC+AB)
		printf("Треугольник является прямоугольным\n");
	else
		printf("Треугольник не является прямоугольным\n");
	return 0;
}
