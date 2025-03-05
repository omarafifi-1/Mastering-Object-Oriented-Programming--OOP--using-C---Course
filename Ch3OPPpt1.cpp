#include <iostream>
using namespace std;

class Stack
{
    int Top;
    int Size;
    int* Arr;

    public:

    friend void viewContent(Stack &x);
    static int StackCount;

    Stack(int x=10)
    {
        StackCount++;
        Top = 0;
        Size = x;
        Arr = new int[Size];
        cout<<"Stack "<<StackCount<<" Created"<<endl;
    }
    ~Stack()
    {
        cout<<"Stack "<<StackCount<<" Destroyed"<<endl;
        StackCount--;
        delete[] Arr;
    }
    void Push(int x);
    int  Pop();
};

void viewContent(Stack &x)
{
    int temp = x.Top;
    for(int i = temp;i>0;--i)
    {
        cout<<x.Arr[i]<<endl;
    }
}

void Stack::Push(int x)
{
    if(Top != Size)
    {
        Top++;
        Arr[Top] = x;
    }
    else
    {
        cout<<"Stack Full"<<endl;
    }
}

int Stack::Pop()
{
    if(Top != 0)
    {
        return Arr[Top--];
    }
    else
    {
        
        return -1;
    }
}

int Stack::StackCount = 0;

int main()
{
    Stack A(10);
    A.Push(5);
    A.Push(4);
    A.Push(3);
    A.Push(2);
    viewContent(A);
    
    return 0;
}
