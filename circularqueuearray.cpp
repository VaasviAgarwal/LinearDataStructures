#include <iostream>
using namespace std;

class cqueuefunctions
{
	private:
	int *cqueue;
	int n;
	int front;
   	int rear;

	public:
	cqueuefunctions(int *a, int size)
	{
		cqueue = a;
		n = size;
       	front = rear = -1;
	}
	bool isfull()
	{
		if((front==0 && rear==n-1) || (front==rear+1)) // front == (rear+1)%max (for front == 0, rear = 6%6 =0 and for other numbers like front = 3, rear = 2 then rear+1 % 6 = 3)
		{
			cout<<"CQueue is full"<<endl;
			return true;
		}
		cout<<"CQueue is not full"<<endl;
		return false;
	}
	bool isempty()
	{
		if(front==-1)
		{
			cout<<"CQueue is empty"<<endl;
			return true;
		}
		cout<<"CQueue is not empty"<<endl;
		return false;
	}
	void encqueue(int val)
	{
		if(isfull())
		{
			cout<<"CQueue Overflow"<<endl;
		}
		else
		{
			cout<<"Element Inserted"<<endl;
            		if (front == -1)
            		{
                		front = 0;
						rear = 0;
            		}
					else 
					{
						//rear = (rear+1)%n
						if (rear==n-1)
						{
							rear = 0;
						}
						else
						{
							rear++;
						}
					}
			cqueue[rear]=val;
		}	
	}
	void decqueue()
	{
		if(isempty())
		{
			cout<<"CQueue Underflow"<<endl;
		}
		else
		{
			cout<<"The element deleted is "<<cqueue[front]<<endl;
			if (front==rear)
			{
				front = -1;
				rear = -1;
			}
			else
			{
				//front = (front+1)%n
				if (front == n-1)
				{
					front = 0;
				}
				else
				{
					front++;
				}
			}
		}
	}
	void display()
	{
		if(isempty())
		{
			front = -1;
			rear = -1;
			return;
        }
		/*
			i = front
			while(i<=rear)
			{
				cout<<cqueue[i]
				i = (i+1)%n
			}
		*/
		int f = front;
		int r = rear;
        cout<<"CQueue elements are : ";
		if (f<=r)
		{
			while(f<=r)
			{
				cout<<cqueue[f]<<" ";
				f++;
			}
			f=0;
		}
		else
		{
			while(f<=n-1)
			{
				cout<<cqueue[f]<<" ";
				f++;
			}
			f=0;
			while(f<=r)
			{
				cout<<cqueue[f]<<" ";
				f++;
			}
		}
		cout<<endl;
	}
};

int main()
{
	cout<<"Enter the size of the cqueue : ";
	int size;
	cin>> size;
	int val;
	int cqueue[size];
	cqueuefunctions ob(cqueue, size);
	char choice;
	do
	{
		cout<<""<<endl;
		cout<<"Enter 1 to Insert element in cqueue"<<endl;
		cout<<"Enter 2 to Delete element from cqueue"<<endl;
		cout<<"Enter 3 to Display elements of the cqueue"<<endl;
		cout<<"Enter 4 to check if the cqueue is full"<<endl;
		cout<<"Enter 5 to check if the cqueue is empty"<<endl;
		cout<<"Enter 0 to exit"<<endl;
		cout<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case '1':
			{
				cout<<"Enter value to be inserted : ";
				cin>>val;
				ob.encqueue(val);
				break;
			}
			case '2':
			{
				ob.decqueue();
				break;
			}
			case '3':
			{
				ob.display();
				break;
			}
			case '4':
			{
				ob.isfull();
				break;
			}
			case '5':
			{
				ob.isempty();
				break;
			}
			case '0':
			{
				cout<<"Program exited"<<endl;
				break;
			}
			default:
			{
				cout<<"Invalid Choice"<<endl;
				break;
			}
		}
	}while(choice!='0');
	return 0;
} 
