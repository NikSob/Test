#include <stdio.h>

int main(void)
{
	int string=0;
	int column =0;
	int num = 32;
	printf(" %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s\n", "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "LF","VT","FF", "CR", "SO", "SI");
	printf(" %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s %4s\n", "DLE", "DC1", "DC2","DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US");
	while (string<6)
	{
		while (column<16)
		{
			printf(" %4c", num++);
			column++;
			while (num>127)
			{
				printf("\b\b\b %3s", "DEL");
				--num;
			}
		}
		printf("\n");
		column = 0;
		string++;
	}
	return 0;
}