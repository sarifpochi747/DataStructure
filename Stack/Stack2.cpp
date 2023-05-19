#include<iostream>
#include<string.h>
using namespace std;

class Stack2
{
private:
    char arr[10000];
    int size = 9999;
    int top;
public:
    Stack2()
    {
        top =0;
        //arr[0] = '999';
    };
    bool isFull()
    {
        if(top == size)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty()
    {
        if(top ==0 )
        {
            return true;
        }
        else{
            return false;
        }
    }

    void push(char n)
    {
        if(!isFull())
        {
            top ++;
            arr[top] = n;
        }
    }

    char pop()
    {
        if(!isFull())
        {
            char temp = arr[top];
            top--;
            return temp;
            
        }
        return 0;
    }

   
    
};

int main()
{
    Stack2 obj;
    string str;
    int n;
    getline(cin,str);
    n = str.length();
	for(int i=0;i<n;i++)
    {
        obj.push(str[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<obj.pop();
    }
}
