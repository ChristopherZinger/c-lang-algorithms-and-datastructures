#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h" 

struct BSTNode *_createBSTNode(int val) {
		struct BSTNode *node;
		node = malloc(sizeof(struct BSTNode));
		node->val = val;
		return node;
}

struct BSTree *createBST() {
		struct BSTree *bst;
		bst = malloc(sizeof(struct BSTree));
		return bst;
}

struct BSTNode *_insertBSTNode(struct BSTNode *node, int val) {
		if (node == NULL) {
				return _createBSTNode(val);
		} else if (val < node->val) {
				node->left = _insertBSTNode(node->left, val);
		} else if (val > node->val) {
				node->right = _insertBSTNode(node->right, val);
		}
		return node;
}

void insertBSTNode(struct BSTree *tree, int val) {
		tree->root = _insertBSTNode(tree->root, val);
};

void inOrderTraversal(struct BSTNode *node) {
		if (node->left != NULL) {
				inOrderTraversal(node->left);
		}
		printf("%d\n", node->val);
		if (node->right != NULL) {
				inOrderTraversal(node->right);
		}
}

struct BSTNode *_findBSTNode(struct BSTNode *node, int val) {
		if (node == NULL) {
				return NULL;
		} else if (node->val == val) {
				return node;
		} else if (val < node->val) {
				return _findBSTNode(node->left, val);
		} else {
				return _findBSTNode(node->right, val);
		}
}

struct BSTNode *findBSTNode (struct BSTree *tree, int val) {
		return _findBSTNode(tree->root, val);
}

struct BSTNode *_getMax(struct BSTNode *node) {
		if (node->right == NULL) {
				return node;
		}
		return _getMax(node->right);
}


struct BSTNode *_deleteBSTNode(struct BSTNode *node, int val) {
		if (node == NULL) {
				return NULL; 
		} else if (val < node->val) {
				node->left = _deleteBSTNode(node->left, val);
				return node;
		} else if (val > node->val) {
				node->right = _deleteBSTNode(node->right, val);
				return  node;
		} else {
				if (node->right == NULL && node->left == NULL) {
						free(node);
						return NULL;
				} else if (node->right == NULL) {
						struct BSTNode * left = node->left;
						free(node);
						return left;
				} else if (node->left == NULL) {
						struct BSTNode * right = node->right;
						free(node);
						return right;
				} else {
						struct BSTNode *predecessor = _getMax(node->left);
						node->val = predecessor->val;
						node->left = _deleteBSTNode(node->left, node->val);
						return node;
				}
		}
}

void deleteBSTNode (struct BSTree *tree, int val) {
		tree->root = _deleteBSTNode(tree->root, val);
}
