#ifndef LINKED_LIST_H 
#define LINKED_LIST_H

struct LinkedList {
		struct LlNode *head;
		int len;
};

struct LlNode {
		int val;
		struct LlNode *next;
};

struct LinkedList *createLinkedList(); 
struct LlNode *createLlNode(int value);
struct LlNode* getLlTail(struct LinkedList *ll);
struct LlNode *insertLlAt(struct LinkedList *ll, int val, int idx);
struct LlNode *popLlHead(struct LinkedList *ll);
struct LlNode *popLlTail(struct LinkedList *ll);
struct LlNode *removeLlVal(struct LinkedList *ll, int val);
void appendLl(struct LinkedList *ll, int val);
void prependLl(struct LinkedList *ll, int val);
void traverseLl(struct LinkedList *ll);

#endif
