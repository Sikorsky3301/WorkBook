#include <iostream>
using namespace std;

class node
{
	public:
	int data;
	node* next;

	node(int data){
		this -> data = data;
		this -> next = NULL;
	}

};

void insertathead(node* &head , int d){
	node* temp = new node(d);
	temp -> next = head;
	head = temp;
}

void print(node* &head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp -> data << " "; 
		temp = temp -> next ;
	}
	cout << endl;

}

int main()
{
	//created a new node 
	node *node1 = new node(10);
	// cout << node1->data << endl;
	// cout << node1->next << endl;



    // head pointed to new node initially 
	node* head = node1;

	print(head);

	// inserting at head 
	insertathead( head , 15);
	insertathead(head , 29);
	print(head);
	return 0;
}