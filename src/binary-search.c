#include <stdio.h>

int binarySearch (int target, int arr[], int size) {
	int startIndex = 0;
	int endIndex = size;

	while(1) {
		if(startIndex == endIndex) {
			if (target == arr[startIndex]) {
				return startIndex;
			} else {
				return -1;
			}
		}

		int pivotIndex = startIndex + ((endIndex - startIndex) / 2);
		int pivotValue = arr[pivotIndex];
		if (pivotValue == target)  {
			return pivotIndex;
		} else if (pivotValue > target) {
			endIndex = pivotIndex - 1;
		} else {
			startIndex = pivotIndex + 1;
		}
	}
}
