/* Basic Implementation of Red Black tree */

#ifndef __RBTREE_H_
#define __RBTREE_H_

#include<stdio.h>
#include<stdlib.h>

#define RBTREE_ERR -1
#define RBTREE_OK 0

#define SET_RED(_n) ((_n)->color = 1)
#define SET_BLACK(_n) ((_n)->color = 0)

typedef struct RBTreeNode {
	RBTreeNode *parent;
	RBTreeNode *left;
	RBTreeNode *right;	
	uint32_t key;
	int color:1; /* bit to store the color*/
	void *data; /* opaque data */
}RBTreeNode;

typedef struct RBTree {
	RBTreeNode *root;
	size_t size;
}RBTree;

RBTree* initTree();
int insertNode(RBTree *root, void *data);
int deleteNode(RBTree *root, void *data);
size_t getSize();

#endif
