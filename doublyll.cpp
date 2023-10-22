#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* prev;
	Node* next;

	Node(int d)
	{
	  this->data=d;
	  this->prev=NULL;
	  this->next=NULL;

	}
	~Node()
	{
	   int val=this->data;
	   if(next!=NULL)
	   {
	   	delete next;
	   	next=NULL;
	   } 
	   cout<<"memory free for node with data"<<val<<endl;
}
};
void print(Node* head)
{
	Node* temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int getlength(Node* head)
{
	int len=0;
	Node* temp=head;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	return len;
}
void insertAthead(Node* &tail,Node* &head,int d)
{
	if(head==NULL)
	{
		Node* temp=new Node(d);
		head=temp;
		tail=temp;
	}
	else{
		Node* temp=new Node(d);
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void insertAttail(Node* &tail,Node* &head,int d)
{
	if(tail==NULL)
	{
		Node* temp=new Node(d);
		tail=temp;
		head=temp;
	}
	else{
		Node* temp=new Node(d);
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void insertatposition(Node* &tail,Node* &head,int position,int d)
{
	if(position==1)
	{
		insertAthead(tail,head,d);
		return;
	}
	Node* temp=head;
	int cnt=1;

	while(cnt<position-1)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL)
	{
		insertAttail(tail,head,d);
		return;
	}
	Node* nodetoinsert=new Node(d);
	nodetoinsert->next=temp->next;
	nodetoinsert->prev=temp;
	temp->next=nodetoinsert;
	temp->next->prev=nodetoinsert;
}
void deleteNode(int position,Node* &head)
{
	if(position==1)
	{
		Node*temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
	else
	{
		Node* curr=head;
		Node* prev=NULL;

		int cnt=1;
		while(cnt<position)
		{
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		curr->prev=NULL;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}
int main()
{
	Node* head=NULL;
	Node* tail=NULL;
	print(head);
	cout<<getlength(head)<<endl;

   insertAthead(tail,head,11);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;

   insertAthead(tail,head,13);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;
 
   insertAttail(tail,head,15);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;
  
   insertatposition(tail,head,2,101);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;
  
   insertatposition(tail,head,1,102);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;
   
   insertatposition(tail,head,6,101);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;

   deleteNode(6,head);
   print(head);
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;
}
