#include <stdio.h>
#include "print_array.h"

void printArray(int arr[], int size) {
		for (int i = 0; i < size; i++) {
				printf("%d, ", arr[i]);
		}
		printf("\n");
}
