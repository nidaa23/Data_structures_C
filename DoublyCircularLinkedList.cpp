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


struct Node* CreateNewNode(int x) {
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data = x;
		new_node->next = NULL;
		new_node->prev = NULL;
		return new_node;
	

}

void Append(int x) {
	if (head == NULL) {
		struct Node* temp = CreateNewNode(x);
		temp->next = head;
		temp->prev = head;
		head = temp;
		tail = temp;
		
	}
	else {
		struct Node* new_node = CreateNewNode(x);

		new_node->prev = tail;
		new_node->next = head;
		head->prev = new_node;
		tail->next = new_node;
		tail = new_node;
	

	}
	length++;
}

void Print() {
	printf("The list: \n");
	struct Node* curr = NULL;
	curr = head;
	while (curr != NULL)
	{
		printf("%d\t", curr->data);
		curr = curr->next;

		if (curr == tail) {
			printf("%d\t", curr->data);
			break;
		}
	}
	printf("\n");

}
struct Node* Search(int x) {


	if (head->data == x) {
		return head;
	}if (tail->data == x) {
		return tail;
	}
	else {
		
		struct Node* curr = head;
		while (curr != tail) {
		
			if (curr->data == x) {
				return curr;
				break;
			}if (curr->next == tail) {
				return NULL;
			}
			
			curr = curr->next;
		}

	}
}

void Update(int oldValue, int newValue) {
	struct Node* temp = Search(oldValue);
	if (temp != NULL) {
		if (temp == tail) {
			tail->data = newValue;
		}
		else {
			struct Node* curr = head;
			while (curr != tail) {

				if (curr == temp) {
					curr->data = newValue;
				}
				curr = curr->next;
			}

		}
	}
	else {
		printf("%s", "Value doesn't exist");
	}
	
}


int main(){

	Append(7);
	Append(5);
	Append(6);
	Append(3);
	Append(4);
	printf("Length of list: %d", length);
	printf("\n\n");
	Print();
	printf("\n\n");
	printf("%d",Search(4)->data);
	printf("\n\n");
	Update(1,9);
	printf("\n\n");
	Print();

	return 0;
}