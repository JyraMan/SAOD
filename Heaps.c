#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define left_child(node) ( (node) * 2 + 1 )
#define right_child(node) ( (node) * 2 + 2 )
#define M 1000000
#define R 1000001

void swap(int * array, int i, int j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
}

void heap_it(int * array, int length, int root)

{
        int leftChild = left_child(root);
        int rightChild = right_child(root);
        int biggest = root;

        if ( leftChild < length && array[root] < array[leftChild] )
    	    biggest = leftChild;
        if ( rightChild < length && array[biggest] < array[rightChild] )
    	    biggest = rightChild;
        if ( biggest != root )
	{
     	   swap(array, biggest, root);
           heap_it(array, length, biggest);
        }
}

void make_heap(int * array, int length)

{
        int i = length / 2;

        for ( ; i >= 0; --i )
        	heap_it(array, length, i);
}

void heap_sort(int * array, int count)

{
        int last;

        make_heap(array, count);
        for ( last = count - 1; last > 0; --last )
	{
        	swap(array, 0, last);
        	heap_it(array, last, 0);
        }
}

int main(void)

{
	clock_t start, end;
        int array[M], i;

        for ( i = 0; i < M; ++i )
        	array[i] = rand() % R;

        printf("Unsorted:\n");
        for ( i = 0; i < M; ++i )
        	printf("%02d ", array[i]);
	start = clock();
        heap_sort(array, M);
	end = clock();
        printf("\nSorted:\n");
        for ( i = 0; i < M; ++i )
        	printf("%02d ", array[i]);
        printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
	printf("\n");

        return 0;
}
