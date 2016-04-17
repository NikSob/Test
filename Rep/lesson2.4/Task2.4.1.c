#include <stdio.h>
 
int main() 
{
	float R,G,B, H,S,V, Max, Min;
	printf("Введите значения R G B в пределах от 0 до 255	:");
	scanf("%f %f %f", &R, &G, &B);
	while(R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
	{
		printf("Введите значения R G B в пределах от 0 до 255:\n");	
		scanf("%f %f %f", &R, &G, &B);
	}
	R = R/255;
	G = G/255;
	B = B/255;
	if (R<B  && R<G)
		Min = R;
	else if (G<B  && G<R) 
		Min = G;
	else Min = B;
	if (R>B  && R>G)
		Max = R;
	else if (G>B  && G>R) 
		Max = G;
	else Max = B;
	if (Max == Min)
		H = 0;
	else if (Max == R && G >= B)
		H = 60*(G-B)/(Max-Min);
	else if (Max == R && G < B)
		H = 60*(G-B)/(Max-Min)+360;
	else if (Max == G)
		H = 60*(B-R)/(Max-Min)+120;
	else if (Max == B)
		H = 60*(R-G)/(Max-Min)+240;
	if (Max == 0)
		S = 0;
	else S = 1 - (Min/Max);
	V = Max;
	if (H>0 && H<=20) 
	printf("Крассный оттенок цвета.\n");
	if (H>20 && H<=45) 
	printf("Оранжевый оттенок цвета.\n");
	if (H>45 && H<=70) 
	printf("Жёлтый оттенок цвета.\n");
	if (H>70 && H<=150) 
	printf("Зелёный оттенок цвета.\n");
	if (H>150 && H<=190) 
	printf("Голубой оттенок цвета.\n");
	if (H>190 && H<=270) 
	printf("Синий оттенок цвета.\n");
	if (H>270 && H<=295) 
	printf("Фиолетовый оттенок цвета.\n");
	if (H>295 && H<=335) 
	printf("Розовый оттенок цвета.\n");
	else
	printf("Крассный оттенок цвета.\n");
	printf("Введённый цвет в системе HSV = %g %g%% %g%%\n", H,S*100, V*100);
	return 0;
}
