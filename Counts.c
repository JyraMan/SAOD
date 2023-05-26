#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define M 1000000
#define R 1000001

void countSort(uint32_t arr[], uint32_t sorted[], int n)
{
	uint32_t *count = calloc(R, sizeof(uint32_t));
	int i;

	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}

	for (i = 1; i < R; i++)
	{
		count[i] += count[i - 1];
	}

	int *used = calloc(R, sizeof(int));

	for (i = n - 1; i >= 0; i--)
	{
		if (!used[arr[i]])
		{
			sorted[count[arr[i]] - 1] = arr[i];
			used[arr[i]] = 1;
		}
		 count[arr[i]]--;
	}

	free(count);
	free(used);
}

int main()

{
	uint32_t *arr = malloc(M * sizeof(uint32_t));
	uint32_t *sorted = malloc(M * sizeof(uint32_t));
	clock_t start, end;

	srand(time(NULL));
	for (int i = 0; i < M; i++)
	{
		arr[i] = rand() % R;
	}

	start = clock();
	countSort(arr, sorted, M);
	end = clock();

	printf("Отсортированный массив элементов:\n");
	for (int i = 0; i < M; i++)
	{
		printf("%d ", sorted[i]);
	}

	printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);

	free(arr);
 	return 0;
}

