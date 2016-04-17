
#include <stdio.h>

int main(void)
{
	float speed, sinA, Time, A, x;
	printf("Введите скорость, с которой было брошено тело(м/с):");
	scanf("%f",&speed);
	printf("Введите угол, под которым было брошено тело(м/с):");
	scanf("%f",&A);
	while (speed<0 || A<0 || A >90)
	{
		printf("Введите корректные значения...\n");
		printf("Введите скорость, с которой было брошено тело(м/с):");
		scanf("%f",&speed);
		printf("Введите угол, под которым было брошено тело(м/с):");
		scanf("%f",&A);
	}
	x=A*3.14159/180;
	sinA=x-(x*x*x/6)+(x*x*x*x*x/120)-(x*x*x*x*x*x*x/5040);
	Time=2*speed*sinA/9.8;
	printf("Время полёта тела = %.2f секунд",Time);
	return 0;
}