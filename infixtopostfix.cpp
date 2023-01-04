#include <iostream>
using namespace std;

class MyStack
{
    private:
    char stack[100];
    int n;
    int top;
    public:
    MyStack(int size)
    {
        stack[size];
        n = size;
        top=-1;
    }
    void push(char val);
    char pop();
    char peek();
    bool empty();
};

void MyStack::push(char val)
{
    top++;
    stack[top] = val;
}

char MyStack::pop()
{
    top--;
    return stack[top+1];
}

char MyStack::peek()
{
    return stack[top];
}

bool MyStack::empty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

int priority(char a)
{
    if(a=='+' || a=='-')
    {
        return 1;
    }
    if(a=='*' || a=='/')
    {
        return 2;
    }
    if(a=='^')
    {
        return 3;
    }
    return 0;
}

int main()
{
    string infix;
    cout<<"Enter the expression :"<<endl;
    cin>>infix;
    infix = infix+"#";
    string postfix = "";
    int s = infix.length();
    MyStack stack(s);
    int i = 0;
    while(infix[i]!='#')
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            postfix = postfix+infix[i];
        }
        else if(infix[i]=='(')
        {
            stack.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stack.peek()!='(')
            {
                postfix = postfix + stack.peek();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            while(!stack.empty() && priority(infix[i])<=priority(stack.peek()))
            {
                postfix = postfix + stack.peek();
                stack.pop();
            }
            stack.push(infix[i]);
        }
        i++;
    }
    while(!stack.empty())
    {
        postfix = postfix+stack.peek();
        stack.pop();
    }
    cout<<"Postfix expression : "<<postfix<<endl;
    return 0;
}