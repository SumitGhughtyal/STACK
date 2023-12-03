#include<iostream>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int overflow();
    int underflow();
    void display();
    int stackTop();

};

Stack::Stack(int size)
{
    this->size=size;
    top=-1;
    S = new int[size]; 
}

Stack::~Stack()
{
    delete[] S;
}

void Stack::push(int x)
{
    if(overflow()) cout<<"Stack Overflow!"<<endl;
    else
    {
        top++;
        S[top]=x;
    }
}

int Stack::pop()
{
    int x=1;
    if(underflow()) cout<<"Stack Underflow!"<<endl;
    else{
        x=S[top];
        top--;
    }
    return x;
}


int Stack::overflow()
{
    if(top==size-1) return 1;
    else return 0;
}

int Stack::underflow()
{
    if(top==-1) return 1;
    else return 0;    
}

int Stack::peek(int index)
{
    int x=-1;
    if(top-index+1<0 || top-index+1==size)
    {
        cout<<"Invalid position!"<<endl;

    } else{
        x = S[top-index+1];

    }
    return x;
}

void Stack::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<S[i]<<" | "<<flush;
    }
    cout<<endl;
}

int Stack::stackTop()
{
    if(underflow()) return -1;
    else return S[top];
}



int main()
{
    int A[]={1,3,5,7,9};
    Stack skt(sizeof(A)/sizeof(A[0]));

    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
    {
        skt.push(A[i]);
    };
    skt.push(11);


    cout<<"Stack Full! "<<skt.overflow()<<endl;

    cout<<"Stack : "<<flush;
    skt.display();

    cout << "Peek at 0th: " << skt.peek(0) << endl;
    cout << "Peek at 3rd: " << skt.peek(3) << endl;
    cout << "Peek at 10th: " << skt.peek(10) << endl;

    // Top element
    cout << "Top element: " << skt.stackTop() << endl;
 
    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << skt.pop() << ", " << flush;
    }
    cout << endl;
    skt.pop();
 
    cout << "Stack empty: " << skt.overflow() << endl;


    return 0;
}
