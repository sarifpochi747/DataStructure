#include<iostream>
using namespace std;

class Queue4{
    private:
        int arr[10000];
        int size;
        int front;
        int count ;
        int rear;
    
    public:
        // constructor
        Queue4(){
            size = 10000 -2;
            count = 0;
            front = 1;
            rear = 0;
        }

        bool isFull(){
            if(rear == size)
            {   
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if(rear < front)
            {   
                return true;
            }

            return false;
        }

        void Enqueue(int n)
        {
            if(!isFull())
            {
                rear++;
                arr[rear] = n;
                count++;
            }
            
        }

        void Dequeue()
        {
            if(!isEmpty())
            {
                int temp = arr[front];
                count --;
                front++;
                cout<<temp<<endl;
            }
            
        };

        int check_count()
        {
            return count;
        }
        void Display()
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void Peek()
        {
            if(!isEmpty())
            {
                cout<<arr[front]<<" "<<arr[rear]<<endl;
            }
        }

};

int main()
{
    Queue4 obj ;
    int num;
	char p;
	do{
		cin >> p;
		if(p == 'e' || p=='E')
		{
			cin >> num;
		}
		else if(p == 'x' || p=='X')
		{
			break;
		}
		switch(p)
		{
			case 'e':
				obj.Enqueue(num);
				break;
			case 'E':
				obj.Enqueue(num);
				break;
			case 'd' :
				obj.Dequeue();
				break;
			case 'D' :
				obj.Dequeue();
				break;
			case 'p'  :
				obj.Display();
				break;
			case 'P'  :
				obj.Display();
				break;
			case 'n':
				cout << obj.check_count();
				cout << "\n";
			case 'N':
				cout << obj.check_count();
				cout << "\n";
				break;
			case 's' :
				obj.Peek();
				break;
			case 'S' :
				obj.Peek();
				break;
		}
	}while(p != 'x' || p != 'X' );

    
}

