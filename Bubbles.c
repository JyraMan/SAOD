#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#define R 1000001
#define M 1000000

void BubbleSort( uint32_t mass[] )
{
        for (int i = 0; i < M; i++)
        {
               mass[i] = rand() % R;
        }
	mass = calloc(R, sizeof(uint32_t));
	uint32_t tmp;
        bool noSwap;

	for (int i = R - 1; i >= 0; i--)
	{
		noSwap = 1;
        	for (int j = 0; j < i; j++)
        	{
        		if (mass[j] > mass[j + 1])
            		{
                		tmp = mass[j];
                		mass[j] = mass[j + 1];
                		mass[j + 1] = tmp;
                		noSwap = 0;
            		}
        	}
        	if (noSwap == 1)
            	break;
    	}
}

int main()
{
	clock_t start, end;
        uint32_t *mass= malloc(M * sizeof(uint32_t));
        start = clock();
        BubbleSort( mass );
        end = clock();
	printf("Отсортированный массив элементов:\n");
        for (int i = 0; i < M; i++)
        {
                printf("%d ", mass[i]);
        }

        printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
	free(mass);

        return 0;
}
