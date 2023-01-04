#include <iostream>
using namespace std;

class MyStack
{
    private:
    int top;
    float stack[100];
    int s;
    public:
    MyStack(int s)
    {
        stack[s];
        this->s = s;
        top = -1;
    }
    void push(float val);
    float pop();
    float peek();
    bool Empty();
};

void MyStack::push(float val)
{
    top++;
    stack[top]=val;
}

float MyStack::pop()
{
    if(!Empty())
    {
        top--;
        return stack[top+1];
    }
    return -1;
}

float MyStack::peek()
{
    return stack[top];
}

bool MyStack::Empty()
{
    return top==-1;
}

bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
    {
        return true;
    }
    return false;
}

float toNum(char ch)
{
    return float(ch-'0');
}

bool isOperand(char ch)
{
    if(ch>='0'&&ch<='9')
    {
        return true;
    }
    return false;
}

float operation(float a, float b, char op)
{
    if(op=='+')
    {
        return b+a;
    }
    else if(op=='-')
    {
        return b-a;
    }
    else if(op=='*')
    {
        return b*a;
    }
    else if(op=='/')
    {
        return b/a;
    }
    else if(op=='^')
    {
        float ans = 1;
        for(int i = 0; i<a;i++)
        {
            ans = ans*b;
        }
        return ans;
    }
    else
    {
        return INT_MIN;
    }
}

int main()
{
    string post;
    cout<<"Enter the postfix expression : ";
    cin>>post;
    int s = post.length();
    MyStack stack(s);
    char a, b;
    for(int i=0;i<s;i++)
    {
        if(isOperator(post[i]))
        {
            a = stack.peek();
            stack.pop();
            b = stack.peek();
            stack.pop();
            stack.push(operation(a,b,post[i]));
        }
        else if(isOperand(post[i]))
        {
            stack.push(toNum(post[i]));
        }
    }
    cout<<"Answer : "<< stack.peek()<<endl;
}
