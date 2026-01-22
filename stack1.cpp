#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

struct Stack
{
    int top;
    int a[MAX];

    Stack()
    {
        top = -1;
    }
    bool push(int x)
    {
        a[++top] = x;
        return true;
    }
    int pop()
    {
        --top;
        return 1;
    }
    int topElement()
    {
        return a[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};



int main()
{
    Stack s;
    s.push(1);
    s.push(2);

    while(!s.isEmpty())
    {
        cout << s.topElement() << "\n";
        s.pop();
    }
    return 0;

}