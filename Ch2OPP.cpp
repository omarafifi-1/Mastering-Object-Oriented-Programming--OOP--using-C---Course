#include <iostream>
using namespace std;

class Stack
{
    int Top;
    int Size;
    int* Arr;

    public:

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
    A.Push(1);
    int x;
    x = A.Pop();
    cout<<x<<endl;
    x = A.Pop();
    cout<<x<<endl;
    x = A.Pop();
    cout<<x<<endl;
    x = A.Pop();
    cout<<x<<endl;
    x = A.Pop();
    cout<<x<<endl;
    A.Push(3);
    x = A.Pop();
    cout<<x<<endl;
    x = A.Pop();
    cout<<x<<endl;
    
    return 0;
}
