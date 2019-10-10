#include <iostream>
#include "stdio.h"
#include <string.h>


struct Node {

	int data;
	struct Node* next;
	struct Node* prev;

};
struct Node* head;


void InsertAtHead(int x) {

	if (head == NULL) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = NULL;
		temp->prev = NULL;

		head = temp;
	}
	else
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
	}

}

void Append(int x) {


	if (head == NULL) {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = NULL;
		temp->prev = NULL;

		head = temp;
	}
	else {
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data =x;
		new_node->next = NULL;
		new_node->prev = NULL;
		struct Node* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_node;
		new_node->prev = curr;

	}

}

void Print() {
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


int main() {

	InsertAtHead(0);
	InsertAtHead(5);
	InsertAtHead(10);
	InsertAtHead(15);
	InsertAtHead(20);
	InsertAtHead(25);
	InsertAtHead(30);
	Print();
	Append(35);
	Append(40);
	Append(45);
	Print();
	getchar();
	return 0;
}
