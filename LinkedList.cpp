#include <iostream>
#include "stdio.h"
#include <string.h>


struct Node {

	int data;
	struct Node* next;

};
struct Node* head;


struct Node* insertIntoList(int data_) {

	if (head == NULL) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data_;
		temp->next = head;

		head = temp;
	}
	else {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = data_;
		temp->next = head;

		head = temp;
	}
	return head;
}

void printList() {

	printf("The list: \n");
	struct Node* curr = NULL;
	curr = head;
	while (curr != NULL)
	{
		printf("%d\t", curr->data);
		curr = curr->next;
	}
	printf("\n");

}
void addNodeToTail(int data_) {

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = data_;
	new_node->next = NULL;
	struct Node* curr = head;
	while (curr->next != NULL) {

		curr = curr->next;
	}
	curr->next = new_node;

}


int main() {
	
	insertIntoList(1);
	insertIntoList(5);
	insertIntoList(6);
	printList();
	addNodeToTail(7);
	addNodeToTail(9);
	printList();

	return 0;

}

