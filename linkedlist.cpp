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

void insertattail(node* &tail , int d){
	node* temp = new node(d);
	tail -> next = temp ;
	tail = tail -> next ;
}





void insertatposition(node* tail ,node* &head , int position , int d ){
	
	if(position == 1){
		insertathead(head , d);
	}


	node* temp = head ;
	int cnt = 1 ;
	while(cnt < position - 1){
		temp = temp -> next ; 
		cnt++;
	}

	if (temp -> next == NULL){
		insertattail(tail , d);
		return ;
	}

	//creating a node for d(data)
	node* nodetoinsert = new node(d);
	nodetoinsert -> next = temp -> next ;
	temp -> next = nodetoinsert; 

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
	node* tail = node1;
	print(head);

	// inserting at head 
	insertathead( head , 15);
	insertathead(head , 29);
	insertattail(tail , 88);
	insertatposition(tail ,head , 3 , 90);
	print(head);
	cout << "head " << head -> data << endl;
	cout << "Tail " << tail -> data << endl;
	
	return 0;
}