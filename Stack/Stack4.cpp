#include<iostream>
using namespace std;

class Stack4{
    public:
        int arr[1000];
        int size;
        int top;
    
    public:
        //cinstructor
        Stack4()
        {
            size = 999;
            arr[0] = 1000;
            top = 0;
        }

        bool isFull()
        {
            return top == size;
        }

        bool isEmpty()
        {
            return size == 0;
        }
        void push(int value)
        {
            if(!isFull())
            {
                top++;
                arr[top] = value;
            }
            else
            {
                cout<<"Stack Full"<<endl;
            }
        }

        int  pop()
        {
            if(!isEmpty())
            {
                int temp = arr[top];
                top--;
                return temp;
            }
            else
            {
                cout<<"Stack UnderFlow"<<endl;
                return 0;
            }
            
        }

        void Display()
        {
            for (int  i = 1; i <= top; i++)
            {
                cout<<arr[i]<<" ";
            }
            
        }
};

int main()
{
    Stack4 obj;
    obj.push(9);
    obj.push(10);
    obj.push(11);
    obj.push(12);
    obj.Display();
}