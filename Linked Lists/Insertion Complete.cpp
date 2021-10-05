#include <iostream>
#include<conio.h>

using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};


void push(Node** head_ref, int new_data)
{

	Node* new_node = new Node();//allocatd a node


	new_node->data = new_data;// data given


	new_node->next = (*head_ref);// the new node is being made as hea


	(*head_ref) = new_node;// head becomes points to new node
}


void insertAfter(Node* prev_node, int new_data)
{

	if (prev_node == NULL)     //check if the given prev_node is NULL
	{
		cout<<"previous node cannot be NULL";
		return;
	}


	Node* new_node = new Node(); //allocate new node


	new_node->data = new_data;//put in the data


	new_node->next = prev_node->next;//Make next of new node as next of prev_node


	prev_node->next = new_node;//move the next of prev_node as new_node
}


void append(Node** head_ref, int new_data)
{

	Node* new_node = new Node();

	Node *last = *head_ref; 


	new_node->data = new_data;


	new_node->next = NULL;


	if (*head_ref == NULL)//linked list empty make new node
	{
		*head_ref = new_node;
		return;
	}


	while (last->next != NULL)
		last = last->next;


	last->next = new_node;
	return;
}


void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}


int main()
{

	Node* head = NULL;


	append(&head, 6);


	push(&head, 7);


	push(&head, 1);


	append(&head, 4);


	insertAfter(head->next, 8);

	cout<<"Created Linked list is: ";
	printList(head);

	return 0;
}


