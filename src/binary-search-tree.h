#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct BSTNode {
		int val;
		struct BSTNode *left;
		struct BSTNode *right;
};

struct BSTree {
		struct BSTNode *root;
};

struct BSTree *createBST();
struct BSTNode *findBSTNode(struct BSTree *tree, int val);

void deleteBSTNode (struct BSTree *tree, int val);
void insertBSTNode(struct BSTree *tree, int val);
void inOrderTraversal(struct BSTNode *node);

#endif
