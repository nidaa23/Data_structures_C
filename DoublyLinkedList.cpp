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
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp;
}






int main() {

	InsertAtHead(10);
	printf("%d\t", head->data);


	getchar();
	return 0;
}
