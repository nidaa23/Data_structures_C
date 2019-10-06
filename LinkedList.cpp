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


int main() {
	
	insertIntoList(1);
	insertIntoList(5);
	insertIntoList(6);
	printList();

	return 0;

}

