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
void addNodeIndex(int index, int data_) {

	int counter = 1;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data_;
	newNode->next = NULL;
	struct Node* curr = head;

	while (curr != NULL)
	{
		if (index == 1) {
			insertIntoList(data_);
		}if (counter - index == -1) {

			Node* temp = curr->next;
			curr->next = newNode;
			Node* nextNode = curr->next;
			nextNode->next = temp;
		}
		counter++;
		curr = curr->next;
	}

}


int main() {
	
	insertIntoList(1);
	insertIntoList(5);
	insertIntoList(6);
	printList();
	addNodeToTail(7);
	addNodeToTail(9);
	printList();
	addNodeIndex(2, 4);
	printList();

	return 0;

}

