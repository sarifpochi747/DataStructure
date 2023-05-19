#include<iostream>
using namespace std;

class Queue3{
	private:
		int arr[1002];
		int front;
		int rear;
		int size;
		int count;
	public:
		Queue3(){
			front = 0;
			rear = 0;
			size = 1000;
			count =0;
		}
		bool isFull(){
			
			if(front == 1 && rear == size || front != 1 && rear == front -1){
				return true;
			}
			else{
				return false;
			}
			
		}
		
		bool isEmpty(){

			if(front == 0 && rear == 0){
				return true;
			}
			else
			{
				return false;
			}
		}
		
		void enqueue(int n){
			if(!isFull())
			{
				
				if(isEmpty())
				{
					front =1;
					rear = 1;
				}
				else
				{
					if(rear < size)
					{
						rear ++;
					}
					else if(rear == size )
					{
						rear = 1;
					}
				}
				count ++;
				arr[rear] = n;
			}
		}
		
		int dequeue(){
			int temp;
			if(!isEmpty())
			{
				temp = arr[front];
				count --;
				if(front == rear){
					front = 0;
					rear = 0;
				}
				else if(front < size)
				{
					front ++;
				}else if( front == size)
				{
					front == 1;
				}
				return temp;
			}
			
			return 0;
		}
		int check_count()
		{
			return count;	
		}
		void peek()
		{
			if(!isEmpty())
			{
				if(front == rear)
				{
					cout<< arr[front]<<endl; 
				}
				else{	
				    cout<< arr[front]<<" " <<arr[rear]<<endl; 
				}
			}
		}
		
		void display()
    	{
        	if(front >0 && rear > 0)
        	{
            	if(front < rear)
            	{
                	for(int i=front;i<=rear;i++)
                	{
                    	cout<<arr[i] <<" ";
                	}
            	}
            	else
            	{
                	for(int i=front;i<=size;i++)
                	{
                   		cout<<arr[i] <<" ";
                	}
                	for(int i=1;i<=rear;i++)
                	{
                    	cout<<arr[i] <<" ";
                	}
            	}
        	}
    	}
	
};

int main(){
	Queue3 obj ;
	int num;
	char p;
	do{
		cin >> p;
		if(p == 'e')
		{
			cin >> num;
		}
		else if(p == 'x')
		{
			break;
		}
		switch(p)
		{
			case 'e':
				obj.enqueue(num);
				break;
			case 'd':
				cout<<obj.dequeue()<<endl;
				break;
			case 'p':
				obj.display();
				cout<<"\n";
				break;
			case 'n':
				cout << obj.check_count();
				cout << "\n";
				break;
			case 's':
				obj.peek();
				break;
			case 'x':
				break;		
		}
	}while(p != 'x' );
};
