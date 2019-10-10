#include <iostream>
#include "stdio.h"
#include <string.h>


struct Node {

	int data;
	struct Node* next;
	struct Node* prev;

};
struct Node* head;

struct  Node* CreateNewNode(int x) {

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = x;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void InsertAtHead(int x) {

	if (head == NULL) {
		struct Node* temp = CreateNewNode(x);
		temp->next = head;
		head = temp;
	}
	else
	{
		struct Node* temp = CreateNewNode(x);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

}

void Append(int x) {


	if (head == NULL) {
		struct Node* temp = CreateNewNode(x);
		temp->next = head;
		head = temp;
	}
	else {
		struct Node* new_node = CreateNewNode(x);
	
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
