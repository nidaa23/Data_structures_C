#include <iostream>
#include "stdio.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



struct Node {

	int data;
	struct Node* next;
	struct Node* prev;

};
struct Node* head;
struct Node *tail;
int length = 0;


struct Node* CreatenewNode(int x) {
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data = x;
		new_node->next = NULL;
		new_node->prev = NULL;
		return new_node;
	

}

int main() {



	return 0;
}