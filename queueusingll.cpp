#include <iostream>
using namespace std;

class Node
{
    public:
    int info;
    Node *next;
    Node(int val)
    {
        info=val;
        next=NULL;
    }
};

class Queue
{
    public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int val);
    void dequeue();
    void peek();
    bool isEmpty();
    void display();
};

void Queue::enqueue(int val)
{
    Node *newNode = new Node(val);
    if(rear==NULL)
    {
        rear = newNode;
        front = newNode;
        return;
    }
    rear->next =newNode;
    rear = newNode;
    cout<<"Element inserted"<<endl;
}

void Queue::dequeue()
{
    Node *temp;
    int data;
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    else if(front==rear)
    {
        temp = front;
        data=front->info;
        delete(temp);
        front = NULL;
        rear = NULL;
    }
    else
    {
        temp = front;
        data = front->info;
        front = front->next;
        delete(temp);
    }
    cout<<"Element deleted : "<<data;
}

void Queue::peek()
{
    if(isEmpty())
    {
        return;
    }
    cout<<"Peek : "<<front->info<<endl;
}

void Queue::display()
{
    Node *temp = front;
    if(isEmpty())
    {
        return;
    }
    cout<<"Queue :  ";
    while(temp!=NULL)
    {
        cout<<temp->info<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

bool Queue::isEmpty()
{
    if(front==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return true;
    }
    cout<<"Queue is not empty"<<endl;
    return false;
}

int main()
{
    Queue q;
    int choice;
    while(true)
    {
        cout<<""<<endl;
        cout<<"*************************"<<endl;
        cout<<"Enter 1 for enqueue"<<endl;
        cout<<"Enter 2 for dequeue"<<endl;
        cout<<"Enter 3 for peek"<<endl;
        cout<<"Enter 4 for isEmpty"<<endl;
        cout<<"Enter 5 for display"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<""<<endl;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to pushed : ";
            int val;
            cin>>val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.isEmpty();
            break;
        case 5:
            q.display();
            break;
        case 0:
            cout<<"Program terminated"<<endl;
            return 0;
        default:
            cout<<"Invalid Choice"<<endl;
        }
    }
}
