#include <stdio.h>
#include "quicksort.h"
#include "./utils/print_array.h"

void quicksort(int arr[],int lo, int hi) {
		if (lo >= hi - 1) {
				return;
		}

		int p_idx = hi - 1;
		int p_val = arr[p_idx];
		int tmp_pointer = lo - 1;

		for(int i = lo; i < hi; i++) {
				if (arr[i] <= p_val ) {
						tmp_pointer++;
						int tmp = arr[tmp_pointer];
						arr[tmp_pointer] = arr[i];
						arr[i] = tmp;
				}
		}

		quicksort(arr, lo, tmp_pointer);
		quicksort(arr, tmp_pointer + 1, hi);
}

int main () {
		int a[] = {2, 1, 5, 6, 4, 5, 2, 1, 10, 8, 20, 40, 12, 45, 33, 4, 14, 35};
		int size = sizeof(a) / sizeof(a[0]);

		printf("print array before and after quicksort:\n");
		printArray(a, size);
		quicksort(a, 0, size);
		printArray(a, size);

		return 0;
}
