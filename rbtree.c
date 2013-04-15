#include "rbtree.h"

inline int  _is_tree_black(RBTree *node){
	return (node->color == 1 ? 0 : 1); 
}
inline int _is_tree_red(RBTree *node){
	return node->color;
}
static size_t strlen(const char *str){
	size_t _size = 0;
	while(*str != '\0'){
		_size++;
		str++;
	}
	return (_size +1); /*including the null termination*/
}

/*sentinel is void black node*/
static  RBTreeNode* _create_sentinel{
	RBTreeNode *sentinel = (RBTreeNode *)malloc(sizeof(*RBTreeNode));
	if(sentinel != NULL){
		sentinel->data = NULL;
		SET_BLACK(sentinel);
	}
	return sentinel;
}



/*key is calculated using a hash function*/  
static uint32_t getKey(const char *buf, size_t len){
        uint32_t  hash = 5381;
        while (len--)
                hash = ((hash << 5) + hash) + (*buf++);
        return hash;
}

RBTree* initTree(){
	RBTree *tree = (RBTree *)malloc(sizeof(*RBTree));
	if(tree != NULL){
		tree->root = NULL;
		tree->size = 0;
	}
}

/* If it is root node, always set it black - as case 1 */
int insertNode(RBTree *tree, void *data){
	if(tree == NULL) goto err;
	
	RBTreeNode *node = (RBTreeNode *)malloc(sizeof(*RBTreeNode));
	if(node == NULL) goto err;	
	node->key = getKey(,(const char *));
	
	if(tree->root == NULL){
		tree->root = node;
		tree->size += 1;
		SET_RED(node);
		return RBTREE_OK;
	} else {
		//TODO
	}

err:
	return  RBTREE_ERR;	
}





