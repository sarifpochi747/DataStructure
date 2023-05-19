#include <iostream>
using namespace std;

class Queue2
{
private:
    int arr[12];
    int size;
    int front;
    int rear;
public:
    Queue2(){
        front=0;
        rear = 0;
        size = 10;
    };

    bool isFull()
    {
         // Queue Full
        if(front == 1 && rear == size || front != 1 && rear == front -1)
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
        // Queue Empty
        if(front ==0 && rear == 0)
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
            if(isEmpty())
            {
                front =1;
                rear =1 ;
            }
            else
            {
                if(rear == size)
                {
                    rear =1;
                }
                else 
                {
                    rear ++;
                }
            }

            arr[rear] = n;
        }
        else
        {

            cout << "Queueu Full" << endl;
        }
    }

    int dequeue()
    {
        if(!isEmpty())
        {
            int temp = arr[front];
            if(front == rear)
            {
                front = 1;
                rear =1;
            }
            else if(front <size )
            {
                front ++;
            }
            else if(front == size)
            {
                front =1;
            }
            return temp;
        }
        else
        {

            cout << "Queueu empty" << endl;
        }
        return 0;
    }

    void display()
    {
        if(front >0 && rear > 0)
        {
            if(front < rear)
            {
                for(int i=front;i<=rear;i++)
                {
                    cout<<arr[i] << endl;
                }
            }
            else
            {
                for(int i=front;i<=size;i++)
                {
                   cout<<arr[i] << endl; 
                }
                for(int i=1;i<=rear;i++)
                {
                    cout<<arr[i] << endl;
                }
            }
        }
    }
};

int main()
{
    Queue2 obj;
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.enqueue(6);
    obj.enqueue(7);
    obj.enqueue(8);
    obj.enqueue(9);
    obj.enqueue(10);
    obj.display();
    cout<<"-----------------"<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<"-----------------"<<endl;
    obj.display();
}
