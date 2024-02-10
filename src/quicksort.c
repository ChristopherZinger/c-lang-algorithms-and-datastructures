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
