#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
		struct LlNode *head;
		int len;
};

struct LlNode {
		int val;
		struct LlNode *next;
};

struct LlNode *createLlNode(int value) {
		struct LlNode *node;
		node = malloc(sizeof(struct LlNode));
		node->val = value;
		return node;
}

struct LinkedList *createLinkedList() {
		struct LinkedList *ll;
		ll = malloc(sizeof(struct LinkedList));
		ll->len = 0;
		return ll;
}

struct LlNode* getLlTail(struct LinkedList *ll) {
		if (ll->head == NULL) {
				return NULL;
		}
		struct LlNode *tail = ll->head;
		while(tail->next != NULL) {
				tail = tail->next;
		}
		return tail
}

void appendLl(struct LinkedList *ll, int val) {
		struct LlNode *oldTail = getTail(ll);
		struct LlNode *newTail = createLlNode(val);

		if (oldTail != NULL) {
				oldTail->next = newTail;
		} else {
				ll->head = newTail;
		}
		ll->len++;
}

void prependLl(struct LinkedList *ll, int val) {
		struct LlNode *newHead = createLlNode(val);
		newHead->next = ll->head;
		ll->head = newHead;
		ll->len++;
}

/** TODO: accumulate items in ArrayList or pass callback function **/
void traverseLl(struct LinkedList *ll) {
		struct LlNode *curr = ll->head;
		while (curr != NULL) {
				printf("%d \n", curr->val);
				curr = curr->next;
		}
}

struct LlNode *popLlHead(struct LinkedList *ll) {
		if (ll->head == NULL) {
				return NULL;
		}
		struct LlNode *oldHead = ll->head;
		ll->head = ll->head->next;
		ll->len--;
		return oldHead;
}

struct LlNode *popLlTail(struct LinkedList *ll) {
		if (ll->head == NULL) {
				return NULL;
		}

		struct LlNode *oldTail = ll->head; 
		struct LlNode *newTail = NULL; 

		while(oldTail->next != NULL) {
				newTail = oldTail;
				oldTail = oldTail->next;
		}

		if (newTail != NULL) {
				newTail->next = NULL;
		} else {
				ll->head = NULL;
		}
		ll->len--;

		return oldTail;
}

struct LlNode *insertLlAt(struct LinkedList *ll, int val, int idx) {
		if (idx > ll->len || idx < 0) {
				return NULL;
		}

		struct LlNode *prev = NULL;
		for (int i = 0; i < idx; i++) {
				if (prev == NULL) {
						prev = ll->head;
				} else {
						prev = prev->next;
				}
		}

		struct LlNode *newNode = createLlNode(val);
		if (prev != NULL) {
				newNode->next = prev->next;
				prev->next = newNode;
		} else {
				newNode->next = ll->head;
				ll->head = newNode;
		}

		ll->len++;
		return newNode;
}

struct LlNode *removeLlVal(struct LinkedList *ll, int val) {
		struct LlNode* prev = NULL;
		while (1) {
				struct LlNode* curr = NULL;
				if (prev == NULL) {
						curr = ll->head;
				} else {
						curr = prev->next;
				}

				if (curr == NULL) {
						return NULL;
				}

				if (curr->val == val) {
						if (prev != NULL) {
								prev->next = curr->next;
						} else {
								ll->head = curr->next;
						}
						ll->len--;
						return curr;
				}
				prev = curr;
		}
}
