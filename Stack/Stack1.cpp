#include<iostream>
#include<string.h>
using namespace std;


class Stack1
{
    private:
        int arr[1000];
        int size;
        int top ;
    
    public:
    // constructor
        Stack1(){
        	size = 999;
            arr[0] =size;
            top = 0;
        }
    bool isFull()
    {
        if(top == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int n)
    {
        if(!isFull())
        {
            top++;
            arr[top] = n;
            
        }
    }

    int  pop()
    {
        if(!isEmpty())
        {
            top--;
        }
        else //ว่างแบบ size ==0
        {
            // Error
            return 1;
        }
        return 0;
    }
    int count()
    {
        return top;
    }
    
};

int main()
{
    Stack1 obj;
    string num;
    getline(cin,num);
    int n = num.length();
    int temp;
    for(int i=0;i<n;i++)
    {
        if(num[i]== '(')
        {
            obj.push(1);
        }
        else if(num[i] == ')')
        {
            temp = obj.pop();
            if(temp == 1) // if size ==0 , pop stack will be error
            {
                cout<<"Error";
                break;
            }
        }
    }
    if(temp ==0 && obj.count() == 0)
    {
        cout<< "Pass";
    }

};



