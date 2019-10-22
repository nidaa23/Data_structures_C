#include <iostream>
#include <iostream>
#include "stdio.h"
#include <string.h>


struct Node
{
	int key_value;
	Node *right;
	Node *left;
};


void createNewNode(int data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->key_value = data;
	new_node->right = NULL;
	new_node->left = NULL;
}
