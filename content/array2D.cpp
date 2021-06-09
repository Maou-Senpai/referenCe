#include <stdio.h>

int main ()
{
	int TwoDArray[5][5] = { {2, 4, 6, 8, 10},
                            {1, 3, 5, 7, 9},
                            {12, 14, 16, 18, 20},
                            {11, 13, 15, 17, 19},
                            {22, 24, 26, 28, 30} };
	
	int i;
	int j;
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (!(i == 0 && j == 0)) printf("\n");
			printf("%d\t Value in i = %d, j = %d", TwoDArray[i][j], i, j);
		}
	}

	return 0;
}
