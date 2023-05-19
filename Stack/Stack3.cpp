#include<iostream>
using namespace std;


class Stack3
{
private:
    int arr[100];
    int size = 99;
    int top;
public:
    Stack3(){
        arr[0] = size;
        top =0;
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
        if(top == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void push(int n)
    {
        if(!isFull())
        {
            top ++;
            arr[top] = n;
        }
        else
        {
            cout<<"FULL"<<endl;
        }
    }
    int pop()
    {
        if(!isEmpty())
        {
            int temp = arr[top];
            top --;
            return temp;
        }
        else
        {
            cout<<"sTaCk UnderFlow"<<endl;
        }
        return 0;
    }
    int peek()
    {
        if(!isEmpty())
        {
            return arr[top];
        }
        else
        {
            cout<<"sTaCk UnderFlow"<<endl;
        }
        return 0;
    }

    void display()
    {
        for(int i=1;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    int count()
    {
        return top;
    }
   
};

int main()
{
    Stack3 obj1;
    char n;
    int num;
    do
    {
        cin >> n;
        if(n == 'X')
        {
            break;
        }
        else if(n == 'U')
        {
            cin >> num;
        }
        switch (n)
        {
            case 'U':
                obj1.push(num);
                break;

            case 'O':
                cout << obj1.pop()<<endl;
                break;  
            case 'T':
                cout<< obj1.peek()<<endl;
                break;
            case 'P':
                obj1.display();
                cout<<"\n";
                break;
            case 'N':
                cout<< obj1.count()<<endl;
                break;
        }  
    } while (n!= 'X');
    

    

}
