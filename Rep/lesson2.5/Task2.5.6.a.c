#include <stdio.h>
#include <assert.h>

float det( int m, float massiv[m][m]);
float det_with_change (int b, int m, float massiv[m][m], float massiv_free[m]);

float det( int m, float massiv[m][m]) 
{
	extern int coun ;
	coun++;
		float mnr[m-1][m-1], new=0;
		int i, a, b,n;
		
		while(m!=1)
		{
			for(b=0; b<m; b++)  
			{
				for(i = 1; i<m; i++) 
				 {
					for (a=0, n = 0; a<m; a++) 
					{
						if (a!=b)
						{
							mnr[i-1][n]=massiv[i][a];
							n++;
						}
					}
				}
				if (b%2==0) {
					new=new + massiv[0][b]*det(m-1, mnr);
				}
				else {
					new=new - massiv[0][b]*det(m-1, mnr);
				}
			}
			return new;
		}
		if(m==1)
			return massiv[0][0];
	}

float det_with_change (int b, int m, float massiv[m][m], float massiv_free[m])
{
	extern int coun ;
	coun++;
		float addition[m][m],back;
		int i, g;
		for(i=0; i<m ; i++)  
		{
			for (g = 0; g < m; g++)
			{
				addition[i][g]=massiv[i][g];
			}	
		}
		for(i=0;i<m;i++)
		 {
			addition[i][b]=massiv_free[i];
			
		}
		back=det(m, addition);
		return back;
	}