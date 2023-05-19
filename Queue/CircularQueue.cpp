#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int arr[1000];
        int size;
        int front;
        int rear;
    
    public:
        //constructor
        CircularQueue()
        {
            size = 999;
            front =0;
            rear  =0;
        }

        bool isEmpty()
        {
            if(front == 0 && rear == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull()
        {
            if((front == 1) && (rear == size) || (front == rear + 1) && (rear < size))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void enQueue(int value)
        {
            if(!isFull())
            {
                if(isEmpty())
                {
                    front = 1;
                    rear = 1;
                }
                else
                {
                    if(rear < size)
                    {
                        rear ++ ;
                    }
                    else if (rear == size)
                    {
                        rear = 1;
                    }
                }
                arr[rear] = value;
                Display();
            }
        }

        int deQueue()
        {
            if(!isEmpty())
            {
                int temp = arr[front];
                if(front == rear) // ในมีตัวตัวเดียว
                {
                    front = 0;
                    rear = 0;
                }
                else if(front < size )
                {
                    front ++;
                }
                else if (front == size)
                {
                    front = 1;
                }
                Display();
                return temp;
            }
            else
            {
                cout<<"Queue is Empty"<<endl;
                return 0;
            }
        }

        void Display()
        {
            if(front >  0 && rear > 0)
            {
                if(front <= rear) // 1,2,3,4
                {
                    for (int  i = front; i <= rear; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    cout<<endl;
                }
                else
                {
                    for (int  i = front; i <= size; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    
                    for (int  i = 1; i <= rear; i++)
                    {
                        cout<<arr[i]<<" ";
                    }
                    cout<<"\n";                    
                    
                }
            }
        }
};

int main()
{
    CircularQueue obj1;
    obj1.enQueue(1);
    obj1.enQueue(2);
    obj1.enQueue(3);
    obj1.enQueue(4);
    obj1.deQueue();
    obj1.enQueue(6);
    obj1.deQueue();
    obj1.deQueue();
    obj1.deQueue();
    obj1.deQueue();
    obj1.enQueue(7);


}