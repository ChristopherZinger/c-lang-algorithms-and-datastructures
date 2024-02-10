#include "./utils/print_array.h"
#include "bubblesort.h"

void bubblesort(int arr[], int size) {
		for (int i = 1; i < size; i++) {
				for (int j = 0; j < size - i; j++) {
						if (arr[j] > arr[j + 1]) {
								int tmp = arr[j + 1];
								arr[j + 1] = arr[j];
								arr[j] = tmp;
						}
				}
		}
}
