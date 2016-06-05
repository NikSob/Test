#include <stdio.h>
#include <assert.h>


float det( int m, float massiv[m][m]);
float det_with_change (int b, int m, float massiv[m][m], float massiv_free[m]);
int det_count();


int main () 
{
	int m,n, g,i,z;
	printf("Введите колличеств столбцов(строк) матрицы:\n");
	scanf("%d", &m);
	assert(m>0);
	float massiv[m][m], massiv_free[m], determinant,det_with_free, answer[m];
	printf("Введите элементы матрицы:\n");
	for (i=0; i<m; i++)
	{
		for(g=0; g<m; g++)
		{
			scanf("%f", &massiv[i][g]);
		}
	}
	printf("Введите строку свободных членов матрицы:\n");
	for (z=0; z<m; z++)
		scanf("%f", &massiv_free[z]);
	determinant = det(m , massiv);
	printf("Значения x:\n");
	for (g = 0; g<m ; g++)
	{
		det_with_free = det_with_change(g, m , massiv, massiv_free);
		printf("x%d = %g;\n", g+1, det_with_free/determinant);
	}
	printf("Функция была вызвана %d раз(-а).\n", det_count()-1);
	return 0;
}
