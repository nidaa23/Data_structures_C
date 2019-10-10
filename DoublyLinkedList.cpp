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

bool isEmpty() {

	bool emptyList = true;
	if (head != NULL) {
		emptyList = false;
	}
	return emptyList;
}

int length(){
	int len = 0;
	struct Node* curr = NULL;
	curr = head;
	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}

	return len;
}

void InsertAtPosition(int x, int position) {

	int counter = 1;
	struct Node* newNode = CreateNewNode(x);
	struct Node* curr = head;

	while (curr != NULL)
	{
		if (position == 1) {
			InsertAtHead(x);
		}if (counter - position == -1) {

			Node* temp = curr->next;
			curr->next = newNode;
			curr->next->prev = curr;
			Node* nextNode = curr->next;
			nextNode->next = temp;
			newNode->prev = curr->next;
		}
		counter++;
		curr = curr->next;
	}

}



void DeleteAtPosition(int position){

	int counter = 1;
	struct Node* curr = head;

	while (curr != NULL)
	{
		if (position == 1) {

			Node* temp = head;
			head->next->prev = NULL;
			head = head->next;
			delete temp;
			break;
		}if (counter - position == -1) {

			Node* toRemove = curr->next;
			Node* temp = curr->next->next;
			curr->next->next->prev = curr;
			curr->next = temp;

			delete toRemove;
		}
		counter++;
		curr = curr->next;
	}

}



void swapNodes(Node *a, Node *b) {

	int temp_data = a->data;
	a->data = b->data;
	b->data = temp_data;
}
int sortNodes(int flag) {
	struct Node* curr = head;
	while (curr->next != NULL) {
		if (curr->data > curr->next->data) {
			swapNodes(curr, curr->next);
			flag=flag+1;
		}
		curr = curr->next;
	}
	return flag;
}
void Sort_List() {
	int flag = 1;
	while (flag != 0) {
		flag=sortNodes(0);
	}
}

int main(){

	bool isEmp = isEmpty();
	printf("Empty list? %s\n", isEmp ? "true" : "false");
	InsertAtHead(10);
	InsertAtHead(20);
	InsertAtHead(30);
	InsertAtHead(40);
	InsertAtHead(50);
	InsertAtHead(60);
	InsertAtHead(70);
	Print();
	Append(5);
	Append(0);
	Print();
	bool isEmp_ = isEmpty();
	printf("Empty list? %s\n",isEmp_ ? "true" : "false");
	int list_len = length();
	printf("Length of list: %d \n", list_len);
	InsertAtPosition(13, 3);
	Print();
	DeleteAtPosition(3);
	Print();
	printf("%s", ".....");
	Sort_List();
	Print();
	getchar();
	return 0;
}
