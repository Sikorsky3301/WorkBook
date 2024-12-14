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

	// destructor 
	~node(){
		int value = this -> data ;
		if(this -> next != NULL ){
			delete next;
			this -> next = NULL;
		}
		cout << "Memory is free for node with data " << value << endl;
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

    // resolving all the edge cases regarding position 
	// 1) 
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

//******************************************

void deletenode(node* &head ,int position ){
	// deleting the start node 
	if(position == 1){
		node* temp = head;
		head = head -> next;
		temp -> next = NULL;
		delete temp;
		// memory free start node 
	}else{
		//deleting any middle node
		node* curr = head ; 
		node* prev = NULL;

		int cnt = 1 ; 
		while (cnt <= position){
			prev = curr;
			curr = curr -> next;
			cnt ++ ;
		}
		// updating the next pointer of the prev node so that it deetaches from the required one.2->4  ~3
		prev -> next = curr -> next;
		curr -> next = NULL ;
		delete curr;
	}
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

	// inserting at head 
	cout << endl;
	insertathead( head , 15);
	insertathead(head , 29);
	insertattail(tail , 88);
	insertatposition(tail ,head , 3 , 90);
	print(head);
	cout << "head " << head -> data << endl;
	cout << "Tail " << tail -> data << endl;
	cout << endl;
	deletenode(head, 1);
	print(head);


	
	
	return 0;

}