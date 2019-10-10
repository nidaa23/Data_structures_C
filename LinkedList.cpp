#include <iostream>
#include "stdio.h"
#include <string.h>


struct Node {

	int data;
	struct Node* next;

};
struct Node* head;

struct Node* insertFront(int toInsert, Node *&head_) {

	if (head_ == NULL) {


		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->data = toInsert;
		temp->next = head_;

		head_ = temp;
	}
	else {
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

		temp->data = toInsert;
		temp->next = head_;

		head_ = temp;
	}
	return head_;
}
struct Node* InsertAtHead(int data_) {

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
void Append(int data_) {

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = data_;
	new_node->next = NULL;
	struct Node* curr = head;
	while (curr->next != NULL) {

		curr = curr->next;
	}
	curr->next = new_node;

}
void InsertAtPosition(int index, int data_) {

	int counter = 1;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data_;
	newNode->next = NULL;
	struct Node* curr = head;

	while (curr != NULL)
	{
		if (index == 1) {
			InsertAtHead(data_);
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
void DeletePosition(int index) {
	int counter = 1;
	struct Node* curr = head;

	while (curr != NULL)
	{
		if (index == 1) {

			Node* temp = head;
			head = head->next;
			delete temp;
			break;
		}if (counter - index == -1) {

			Node* toRemove = curr->next;
			Node* temp = curr->next->next;
			curr->next = temp;

			delete toRemove;
		}
		counter++;
		curr = curr->next;
	}

}


void Reverse() {
	struct Node* curr = head;


	Node* temp_ = NULL;
	while (curr != NULL) {


		insertFront(curr->data, temp_);
		curr = curr->next;
	}

	head = temp_;


}
int main() {

	InsertAtHead(1);
	InsertAtHead(5);
	InsertAtHead(6);
	Print();
	Append(7);
	Append(9);
	Print();
	InsertAtPosition(2, 4);
	Print();
	DeletePosition(1);
	Print();
	DeletePosition(3);
	Print();
	Append(3);
	Append(4);
	Append(2);
	Print();
	printf("\n");
	printf("%s", "reversed List:");
	printf("\n");
	Reverse();
	Print();
	getchar();
	return 0;

}