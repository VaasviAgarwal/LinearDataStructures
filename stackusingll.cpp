#include <iostream>
using namespace std;

class Node
{
    public:
    Node *next;
    int info;
    Node(int val)
    {
        info = val;
        next = NULL;
    }
};

class MyStack
{
    public:
    Node *top;
    MyStack()
    {
        top = NULL;
    }
    void push(int val);
    void pop();
    void peek();
    bool isEmpty();
    void display();
};

void MyStack::push(int val)
{
    Node *newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

void MyStack::pop()
{
    Node *temp;
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        temp = top;
        cout<<"Element popped : "<<top->info<<endl;
        top = top->next;
        delete(temp);
    }
}

void MyStack::peek()
{
    if(isEmpty())
    {
        cout<<"No peek"<<endl;
    }
    else
    {
        cout<<"Peak : "<<top->info<<endl;
    }
}

bool MyStack::isEmpty()
{
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
        return true;
    }
    cout<<"Stack is not empty"<<endl;
    return false;
}

void MyStack::display()
{
    Node *temp = top;
    if(isEmpty())
    {
        return;
    }
    cout<<"Stack :  ";
    while(temp!=NULL)
    {
        cout<<temp->info<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    MyStack s;
    int choice;
    while(true)
    {
        cout<<""<<endl;
        cout<<"*************************"<<endl;
        cout<<"Enter 1 for push"<<endl;
        cout<<"Enter 2 for pop"<<endl;
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
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.display();
            break;
        case 0:
            cout<<"Program terminated"<<endl;
            return 0;
        default:
            cout<<"Invalid Choice"<<endl;
        }
    }
}