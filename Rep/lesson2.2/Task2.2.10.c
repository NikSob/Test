
#include <stdio.h>

int main(void) 
{
	printf("Количество байтов в типах:\n");
	printf("Char        = %zd;\n",sizeof (char));
	printf("Short       = %zd;\n",sizeof (short));
	printf("Int         = %zd;\n",sizeof (int));
	printf("Float       = %zd;\n",sizeof (float));
	printf("Long        = %zd;\n",sizeof (long));
	printf("Long long   = %zd;\n",sizeof (long long));
	printf("Double      = %zd;\n",sizeof (double));
	printf("Long double = %zd.\n",sizeof (long double));
	return 0;
}

