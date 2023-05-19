#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	Node *next;
	int data;

	public:
	Node(int data)
    {
		this->data = data;
	}
};

class LinkList
{
	public:
	Node *head;
	int size;

	public:
	LinkList()
	{
		size = 0;
	}
		
	void Print()
		{
			for(Node *h = head ; h != NULL ; h = h->next )
			{
				cout<<h->data<<" ";
			}
			cout<<endl;
		}
		
	void insertLL(int data, int i)
		{
			if(size==0 && i==0)//0 size ==0 and i == o
			{
				head = new Node(data);
				head->next = NULL;
				size = 1;
                Print();
			}
			else if (i>=0&&i<=size&&size!=0)
			{
				if(i == 0)
				{
					Node *h = new Node(data); 
					h->next = head;
					head = h;
					size++;
                    Print();
				}
				else
				{
					int ni=1; 
					for(Node *h = head ; h != NULL ; h = h->next)
					{
						if(ni == size)
                        {
							Node *n = new Node(data);
							n->next = h->next; 
							h->next = n;
							size++;
                            Print();
							break;
						}
						ni++;
					}
				}
			}
		};
		
		
	void deleteLL(int i)
		{
			if(0 <= i && i<=size &&size>1)
			{
				if(i == 0)
				{
					head = head->next;
					size--;
				}
				else
				{
					int ni = 1; 
					for(Node *h = head ; h != NULL ; h = h->next)
					{
						if(ni == 1)
						{
							h->next=h->next->next;
							size--;
							break;
						}
						ni++;
					}
				}
			}
		}
	bool Search(int n)
	{
		for(Node *h=head;h!=NULL;h=h->next)
		{
			if(h->data == n)
			{
				return true;
				break;
			}
			else
			{
				return false;
			}
		}
	}
		
};



int main()
{
	
	char choice;
	int input,id;
	LinkList* ll  = new LinkList() ;
	do{
		cin>>choice;
		switch(choice)
		{
			case 'I':
				{
					cin>>input;
					cin>>id;
					//cout<<input<<id;
					ll->insertLL(input,id);
					break;
				}
			case 'D':
				{
					cin>>id;
					ll->deleteLL(id);
					break;
				}
			case 'E':
				{
					break;
				}
			default:
            {
                cout<<"Invaild choice\n";
            }
		}
	}while(choice!='E');

}
