#include<iostream>
using namespace std;

class Node1{
    public:
        Node1 *next;
        int data;
    
    public:
     	// constructor
        Node1(int data)
        {
            this->data = data;
        }	
};

class singlyLinkedList{
	public:
		Node1 *head;
		int size;
	
	public:
		//constructor
		singlyLinkedList()
		{
			size = 0;
		}
		
		singlyLinkedList(int value)
		{
			//create object
			head = new Node1(value);
			head->next = NULL;
			size = 1;
		}
		
		//search method
		bool Search(int value)
		{
			for(Node1 *h=head;h != NULL;h=h->next)
			{
				if(h->data == value)
				{
					return true;
				}
			}
			return false;
		}
		
		//display method
		
		void display()
		{
			for(Node1 *h=head; h!=NULL ; h= h->next)
			{
				cout<<h->data<<"\t";
			}
			cout<<endl;
		}
		
		// insert method
		void insert(int i,int value)
		{
			if(i>=0 && i<=size)
			{
				// insert index == 0
				if(i == 0)
				{
					// create object
					Node1 *n = new Node1(value);
					n->next = head;
					head = n;
					size ++;
				}
				
				// inser index != 0
				else
				{
					int ni =1;
					for(Node1 *h=head;h!= NULL;h = h->next)
					{
						if( ni == i)
						{
							// create object
							Node1 *n = new Node1(value);
							n->next = h->next;
							h->next = n;
							size ++;
							break;
						}
						ni++;
					}
				}
			}
		}

		// delete method
		void Delete(int i)
		{
			if(i>=0 && i<= size && size > 1)
			{
				if( i == 0)
				{
					head = head->next;
					size --;
				}
				else 
				{
					int ni =1;
					for(Node1 *h=head;h != NULL;h = h->next)
					{
						if(ni == i)
						{
							h->next = h->next->next;
							size --;
							break;
						}
						ni ++;
					}
				}
			}
		}
};

int main()
{
	singlyLinkedList *l = new singlyLinkedList(10); //size 1
	//l->display(); // 10  
	l->insert(0,5); // size 2
	//l->display(); // 5 10
	l->insert(2,12); // size 3
	//l->display();// 5 10 12
	l->insert(1,25); // size 4
	l->insert(3,30); // size 5
	cout<<l->Search(25)<<endl;
	l->display(); // 5 25 10 30 12
	cout<<"head "<<l->head->data<<"\taddress "<<l->head->next<<endl;
	l->Delete(2);
	l->display();
	cout<<"head "<<l->head->data<<"\taddress "<<l->head->next->next->next->next<<endl;
};

    
