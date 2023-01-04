#include <iostream>
using namespace std;

class MyQueue
{
    private:
    int queue[100];
    int s;
    int front;
    int rear;
    public:
    MyQueue(int s)
    {
        this->s = s;
        queue[s];
        front = rear = -1;
    }
    void enqueue(int val);
    void dequeue();
    void peek();
    bool isFull();
    bool isEmpty();
    void display();
};

void MyQueue::enqueue(int val)
{
    if(isFull())
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    if(front==-1)
    {
        front = 0;
    }
    rear++;
    queue[rear]=val;
    cout<<"Element Inserted"<<endl;
}

void MyQueue::dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue underflow"<<endl;
        return;
    }
    cout<<"Element popped : "<<queue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }
    front++;
}

void MyQueue::peek()
{
    if(isEmpty())
    {
        cout<<"No peek"<<endl;
        return;
    }
    cout<<"Peek : "<<queue[front];
}

bool MyQueue::isEmpty()
{
    if(front==-1 || front>rear)
    {
        cout<<"Queue is Empty"<<endl;
        return true;
    }
    cout<<"Queue is not Empty"<<endl;
    return false;
}

bool MyQueue::isFull()
{
    if(rear==s-1)
    {
        cout<<"Queue is Full"<<endl;
        return true;
    }
    cout<<"Queue is not Full"<<endl;
    return false;
}

void MyQueue::display()
{
    if(isEmpty())
    {
        return;
    }
    cout<<"Queue :  ";
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<"  ";
    }
    cout<<endl;
}

int main()
{
    int s,val;
    cout<<"Enter the size of the Queue : ";
    cin>>s;
    MyQueue q(s);
    char choice;
    while(true)
    {
        cout<<endl;
        cout<<endl;
        cout<<"Enter 1 for enqueue"<<endl;
        cout<<"Enter 2 for dequeue"<<endl;
        cout<<"Enter 3 for Peek"<<endl;
        cout<<"Enter 4 for isEmpty"<<endl;
        cout<<"Enter 5 for isFull"<<endl;
        cout<<"Enter 6 for display"<<endl;
        cout<<"Enter 0 to Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case '1':
            cout<<"Enter value to be inserted : ";
            cin>>val;
            q.enqueue(val);
            break;
        case '2':
            q.dequeue();
            break;  
        case '3':
            q.peek();
            break; 
        case '4':
            q.isEmpty();
            break;   
        case '5':
            q.isFull();
            break; 
        case '6':
            q.display();
            break; 
        case '0':
            cout<<"Program terminated"<<endl;
            return 0;
        default:
            cout<<"Invalid Choice Entered"<<endl;
            break;
        }
    }
}