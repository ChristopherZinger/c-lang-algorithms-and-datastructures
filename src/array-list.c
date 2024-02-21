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

// TODO - try to use memcpy to copy the array;
void insertAtAL(struct ArrayList *al, int val, int idx) {
        if (idx > al->len + 1 || idx < 0) {
                return;
        }
        if (al->len >= al->capacity) {
                int newCapacity = 2 * al->capacity;
                int *newArr = malloc(newCapacity * sizeof(int));
                for (int i = 0; i < al->len + 1; i++) {
                        if (i < idx) {
                                newArr[i] = al->arr[i];
                        } else if (i > idx) {
                                newArr[i] = al->arr[i - 1];
                        } else {
                                newArr[i] = val;
                        }
                }
                al->capacity = newCapacity;
                al->arr = newArr;
        } else {
                 for (int i = al->len; i > idx; i--) {
                        al->arr[i] = al->arr[i - 1];
                 }
                 al->arr[idx] = val;
        }
        al->len++;
}

void pushAL(struct ArrayList *al, int val) {
        insertAtAL(al, val, al->len);
}

// void enqueue(struct ArrayList *al, int val) {}

// int dequeAL( struct ArrayList *al) {}
// int popAL(struct ArrayList *al,  int val) {}
// int removeAtAL(struct ArrayList *al, int idx)

int main () {
        struct ArrayList *al = createArrayList(3);
        for (int i = 0; i < 10; i++) {
                pushAL(al, i);
        }

        // for (int i = 0; i < 30; i++) {
        //         pushAL(al, i);
        // }

        for (int k = 0; k < al->len; k++) {
                printf("hello: %d\n", al->arr[k]);
        }

        printf("len: %d\n", al->len);
        printf("cap: %d\n", al->capacity);

        return 0;
}
