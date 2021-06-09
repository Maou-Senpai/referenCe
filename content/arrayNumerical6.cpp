#include <stdio.h>
int main()
{
 int i, j, A[3][5] = {{50, 120, 30, 150, 80}, {140, 70, 110, 90, 100}, {30, 20, 0, 60, 40}};

 int largest;

 // print the whole array
 for(j = 0; j <= 2; j = j + 1)
     {
     for(i = 0; i <= 4; i = i + 1)
         printf("%3d ", A[j][i]);
         printf("\n");
     }

 printf("\n");

 for(i = 0; i <= 4; i = i + 1)
     {
     largest = A[0][i];
     for(j = 1; j <= 2; j = j + 1)
         if(A[j][i] > largest)
         largest = A[j][i];
         printf("The largest in column %d is: %d\n", i, largest);
     }
}
