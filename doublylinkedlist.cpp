#include <iostream>
using namespace std;

class Node
{
	public:
	Node *prev;
	Node *next;
	int val;
	Node(int info)
	{
		prev = NULL;
		next = NULL;
		val = info;
	}
};

class DoublyLinkedList
{
	Node *start;
	public:
	DoublyLinkedList()
	{
		start = NULL;
	}
	void addEnd(int val);
	void addBeginning(int val);
	void deleteEnd();
	void deleteBeginning();
	void display();
	void count();
};

void DoublyLinkedList::addEnd(int val)
{
	Node *NewNode = new Node(val);
	if(start == NULL)
	{
		start = NewNode;
	}
	else
	{
		Node *temp = start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		NewNode->prev = temp;
		temp->next=NewNode;
	}
	cout<<"Node added at End"<<endl;
}

void DoublyLinkedList::addBeginning(int val)
{
	Node *NewNode = new Node(val);
	if(start == NULL)
	{
		start = NewNode;
	}
	else
	{
		NewNode->next=start;
		start->prev=NewNode;
		start = NewNode;
	}
	cout<<"Node added at Beginning"<<endl;
}

void DoublyLinkedList::deleteEnd()
{
	if(start == NULL)
	{
		cout<<"List is Empty, Therefore, no node deleted"<<endl;
	}
	else
	{
		Node *temp = start;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		Node *t = temp->next;
		temp->next = NULL;
		int data = t->val;
		delete(t);
		cout<<"Data deleted : "<<data;
	}
}

void DoublyLinkedList::deleteBeginning()
{
	if(start == NULL)
	{
		cout<<"List is Empty, Therefore, no node deleted"<<endl;
	}
	else
	{
		Node *temp = start;
		start = start->next;
		start->prev = NULL;
		int data = temp->val;
		delete(temp);
		cout<<"Data deleted : "<<data;
	}
}

void DoublyLinkedList::display()
{
	if(start == NULL)
	{
		cout<<"List is Empty"<<endl;
	}
	else
	{
		Node *temp = start;
		cout<<"List :  ";
		while(temp!=NULL)
		{
			cout<<temp->val<<"  ";
			temp=temp->next;
		}
		cout<<endl;
	}
}  

void DoublyLinkedList::count()
{
	int c = 0;
	Node *temp = start;
	while(temp!=NULL)
	{
		c = c+1;
		temp=temp->next;
	}
	cout<<"Number of Nodes : "<<c<<endl;
}

int main()
{
	int choice=1;
	DoublyLinkedList dll;
	int val;
	do
	{
		cout<<endl;
		cout<<"Enter 1 to add at End"<<endl;
		cout<<"Enter 2 to add at Beginning"<<endl;
		cout<<"Enter 3 to end at End"<<endl;
		cout<<"Enter 4 to end at Beginning"<<endl;
		cout<<"Enter 5 to display"<<endl;
		cout<<"Enter 6 to count"<<endl;
		cout<<"Enter 0 to End"<<endl;
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			cout<<"Enter your value : ";
			cin>>val;
			dll.addEnd(val);
			break;
			case 2:
			cout<<"Enter your value : ";
			cin>>val;
			dll.addBeginning(val);
			break;
			case 3: 
			dll.deleteEnd();
			break;
			case 4:
			dll.deleteBeginning();
			break;
			case 5:
			dll.display();
			break;
			case 6:
			dll.count();
			break;
			case 0:
			cout<<"Program terminated"<<endl;
			break;
			default:
			cout<<"Invalid Choice"<<endl;
		}
	}
	while(choice!=0);
	return 0;
}                     