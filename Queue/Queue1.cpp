#include<iostream>
using namespace std;

class Queue1
{
private:
    int arr[11];
    int size = 10;
    int front;
    int rear;
public:
    Queue1(){
        front= 1;
        rear =0;
    };

    bool isEmpty()
    {
        if(front > rear)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull()
    {
        if(rear == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int n)
    {
        if(!isFull())
        {
            rear++;
            arr[rear] = n;
        }
        else
        {
            cout << "Queue Full" << endl;
        }
    }

    int dequeue()
    {
        if(!isEmpty())
        {
            int temp = arr[front];
            front ++;
            return temp;
        }
        else
        {
            cout<< "Queue Empty"<<endl;
        }
        return 0;
    }

    void display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    
};

int main()
{
    Queue1 obj1;
    obj1.enqueue(1);
    obj1.enqueue(2);
    obj1.enqueue(3);
    obj1.enqueue(4);
    obj1.enqueue(5);
    obj1.enqueue(6);
    obj1.enqueue(7);
    obj1.enqueue(8);
    obj1.enqueue(9);
    obj1.enqueue(10);
    obj1.display();

}
