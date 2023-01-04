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
    string inf;
    cout<<"Enter the expression :"<<endl;
    cin>>inf;
    inf = "#" + inf;
    string prefix = "";
    int s = inf.length();
    MyStack stack(s);
    int i = 0;
    string infix = "";
    for(i = s-1; i>=0;i--)
    {
        infix = infix+inf[i];
    }
    i=0;
    while(infix[i]!='#')
    {
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
        {
            prefix = prefix+infix[i];
            i++;
        }
        else if(infix[i]==')')
        {
            stack.push(infix[i]);
            i++;
        }
        else if(infix[i]=='(')
        {
            while(stack.peek()!=')')
            {
                prefix = prefix + stack.peek();
                stack.pop();
            }
            stack.pop();
            i++;
        }
        else
        {
            while(!stack.empty() && priority(infix[i])<priority(stack.peek()))
            {
                prefix = prefix + stack.peek();
                stack.pop();
            }
            stack.push(infix[i]);
            i++;
        }
    }
    while(!stack.empty())
    {
        prefix = prefix + stack.peek();
        stack.pop();
    }
    string pre = "";
    for(i=s-2;i>=0;i--)
    {
        pre = pre+prefix[i];
    }
    cout<<"Prefix expression : "<<pre<<endl;
    return 0;
}