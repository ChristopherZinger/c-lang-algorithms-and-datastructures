#include "binary-search.h"

int binarySearch (int target, int arr[], int size) {
	int lo = 0;
	int hi = size;

	while(1) {
		if(lo > hi) { 
		    return -1;
		}

		int pivotIndex = lo + ((hi - lo) / 2);
		int pivotValue = arr[pivotIndex];
		if (pivotValue == target)  {
			return pivotIndex;
		} else if (pivotValue > target) {
			hi = pivotIndex - 1;
		} else {
			lo = pivotIndex + 1;
		}
	}
}
