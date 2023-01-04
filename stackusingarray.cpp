#include <iostream>
using namespace std;

class MyStack
{
    private:
    int stack[100];
    int n;
    int top;
    public:
    MyStack(int size)
    {
        stack[size];
        n = size;
        top = -1;
    }
    void push(int val);
    void pop();
    void peek();
    bool isFull();
    bool isEmpty();
    void display();
};

void MyStack::push(int val)
{
    if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
        top++;
        stack[top]=val;
        cout<<"Element pushed";
}

void MyStack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<"Element Popped : "<<stack[top]<<endl;
    top--;
}

void MyStack::peek()
{
    if(isEmpty())
    {
        cout<<"Therefore, no peek"<<endl;
    }
    cout<<"Peek Element : "<<stack[top]<<endl;
}

bool MyStack::isFull()
{
    if(top==n-1)
    {
        cout<<"Stack is Full"<<endl;
        return true;
    }
    cout<<"Stack is not Full"<<endl;
    return false;
}

bool MyStack::isEmpty()
{
    if(top==-1)
    {
        cout<<"Stack is Empty"<<endl;
        return true;
    }
    cout<<"Stack is not Empty"<<endl;
    return false;
}

void MyStack::display()
{
    if(isEmpty())
    {
        return;
    }
    cout<<"Stack :  ";
    for(int i = 0;i<=top;i++)
    {
        cout<<stack[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int size;
    cout<<"Enter size of stack : ";
    cin>>size;
    MyStack s(size);
    int choice;
    while(true)
    {
        cout<<""<<endl;
        cout<<"*************************"<<endl;
        cout<<"Enter 1 for push"<<endl;
        cout<<"Enter 2 for pop"<<endl;
        cout<<"Enter 3 for peek"<<endl;
        cout<<"Enter 4 for isFull"<<endl;
        cout<<"Enter 5 for isEmpty"<<endl;
        cout<<"Enter 6 for display"<<endl;
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
            s.isFull();
            break;
        case 6:
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