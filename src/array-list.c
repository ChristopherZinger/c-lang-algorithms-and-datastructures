#include <stdio.h>
#include <stdlib.h>

struct ArrayList {
		int capacity;
		int len;
		int *arr;
};

void _resizeAL(struct ArrayList *al);

struct ArrayList *createArrayList (int capacity) {
		struct ArrayList *al;
		int *arr = malloc(capacity * sizeof(int));
		al = malloc(sizeof(struct ArrayList));
		al->capacity = capacity;
		al->len = 0;
		al->arr = arr;
		return al;
}

void pushAL(struct ArrayList *al, int val) {
		if (al->len >= al->capacity) {
				_resizeAL(al);
		}
		al->arr[al->len] = val;
		al->len++;
}
// void insertAtAL(struct ArrayList *al, int val; int idx) {}
// void enqueue(struct ArrayList *al, int val) {}

// int dequeAL( struct ArrayList *al) {}
// int popAL(struct ArrayList *al,  int val) {}
// int removeAtAL(struct ArrayList *al, int idx)
void _resizeAL(struct ArrayList * al) {
		int newCapacity = 2 * al->capacity;
		int *newArr = malloc(newCapacity * sizeof(int));
		for (int i = 0; i < al->len; i++) {
				newArr[i] = al->arr[i];
		}
		free(al->arr);
		al->arr = newArr;
		al->capacity = newCapacity;
}

int main () {
		struct ArrayList *al = createArrayList(10);
		for (int i = 0; i < 30; i++) {
				pushAL(al, i);
		}

		for (int k = 0; k < al->len; k++) {
				printf("hello: %d\n", al->arr[k]);
		}

		printf("len: %d", al->len);
		printf("cap: %d", al->capacity);

		return 0;
}
