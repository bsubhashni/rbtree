#include "rbtree.h"

static inline int  _is_tree_black(RBTree *node){
	return (node->color == 1 ? 0 : 1); 
}
static inline int _is_tree_red(RBTree *node){
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

static void left_rotate(RBTree *tree, RBTreeNode *x){
    RBTreeNode *y = x->right;
    if(!y) return;

    x->right = y->left;
    if(y->left != NULL){
        y->left->parent = x;   
    }
    y->parent = x->parent;
    if(x->parent == NULL){
        tree->root = y;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    return;
}

static void right_rotate(RBTree *tree, RBTreeNode *x){
    RBTreeNode *y = x->parent;
    if(!y || x != y->left) return;
    
    if(y->parent == NULL){
        tree->root = x;
    }
    else if(y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    y->left = x->right;
    x->right->parent = y;
    x->parent = y->parent;
    x->right = y;
    y->parent = x;
    return;
}

static void insert_fixup(RBTree *tree, RBTreeNode *node){
    RBTreeNode *uncle = NULL;

    while(node->parent->color == RED){
        if(node->parent == node->parent->parent->left){
            uncle = node->parent->parent->right;    
        }
        if(uncle->color == RED){
            node->parent
        }
    }
    return;
}
RBTree* initTree(){
	RBTree *tree = (RBTree *)malloc(sizeof(*RBTree));
	if(tree != NULL){
		tree->root = NULL;
		tree->size = 0;
	}
    return tree;
}

/* If it is root node, always set it black - as case 1 */
int insertNode(RBTree *tree, char *data){
	if(tree == NULL) goto err;
	
	RBTreeNode *new_node = (RBTreeNode *)malloc(sizeof(*RBTreeNode));
	if(new_node == NULL) goto err;	
	new_node->key = getKey(data, strlen(data));
	
	if(tree->root == NULL){
		tree->root = node;
		tree->size += 1;
		SET_BLACK(new_node);
		return RBTREE_OK;
	} else {
        RBTreeNode *parent = NULL;
        RBTreeNode *node = tree->root; 
        while(node){
            parent = node;
            if(new_node->key < node->key){
                node = node->left;
            }
            else{
                node = node->right;
            }
        }
        if(new_node->key < parent->key){
            parent->left = new_node;
        }
        else{
            parent->right = new_node;
        }
        new_node.left = NULL;
        new_node.right = NULL;
        new_node.parent = parent;
        SET_RED(new_node);
        insert_fixup(tree,new_node);
        return RBTREE_OK; 
	}

err:
	return  RBTREE_ERR;	
}





