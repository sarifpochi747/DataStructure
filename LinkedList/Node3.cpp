#include<iostream>
using namespace std;

class Node3{
    //attribute
    public:
        int id;
        Node3 *next;

    //method
    public:
        //constructor
        Node3(int i)
        {
            this->id = i;

        }
};

class SinglyLinkedList{
    //attribute
    public:
        int size;
        Node3 *head;
    
    //method
    public:
        //constructor
        SinglyLinkedList()
        {
            size =0;
        }

        void Insert(int data,int i)
        {
            // start create Head Node
            if(size == 0 && i== 0)
            {
                //create object Node head,then point head to Node
                head = new Node3(data);
                head->next = NULL;
                size = 1;
                Display();
            }
            else if(i>=0 && i <=size && size != 0)
            {
                //insert index ==0
                if(i == 0)
                {
                //create obj Node
                    Node3 *n = new Node3(data);
                    n->next = head;
                    head = n;
                    size ++;
                
                
                }
                else
                {
                    int ni = 1;
                    for(Node3 *h=head;h != NULL;h = h->next)
                    {
                        if(ni == i)
                        {
                            //create object Node
                            Node3 *n = new Node3(data);
                            n->next = h->next;
                            h->next = n;
                            size++;
                            break;
                        }
                        ni++;
                    }
                }
                Display();
                
            }
        }

        // method delete
        void Delete(int i)
        {
            if(i>=0 && i<=size && size >1)
            {
                //delete Node index ==0
                if(i==0)
                {
                    head = head->next;
                    size --;
                }
                else
                {
                    int ni =1;
                    for(Node3 *h=head;h!=NULL;h=h->next)
                    {
                        if(ni == i)
                        {
                            h->next = h->next->next;
                            size--;
                            break;
                        }
                        ni++;
                    }
                }
                Display();
            }
        }

        void Display()
        {
            for(Node3 *h=head;h!=NULL;h=h->next)
            {
                cout<<h->id<<" ";
            }
            cout<<endl;
        }

        bool  Search(int n)
        {
            bool temp;
            if(size == 0)
            {
                temp = false;
            }
            else
            {
                for(Node3 *h=head;h!=NULL;h=h->next)
                {
                    //found value n
                    if(h->id == n)
                    {
                        temp = true;
                        break;
                    }
                    else
                    {
                        temp = false;
                    }
                }
            }
            return temp;
        }
            

        //method index
        int index(int data)
        {
            int i=0;
            int temp = i;
            if(size > 0)
            {
                for(Node3 *h=head;h!=NULL;h=h->next)
                {
                    i++;
                    if(h->id == data)
                    {
                        temp = i-1;
                        break;
                    }
                    else
                    {
                        temp = size;
                    }
                }
            }
            
            return temp;
        }
        
};

int main()
{
    //create object head
    SinglyLinkedList *n = new SinglyLinkedList();
    char c ;
    int id;
    int index;
    do
    {
    	cin >> c;

        //switch case
        switch (c)
        {
        case 'I':
            cin >> id;//100
            cin >> index; //0
            //id not available
            if(!(n->Search(id)))
            {
                //find index 
                index = n->index(index);
                n->Insert(id,index);
            }
            break;
        
        case 'D':
            cin >> id;
            //id available
           if(n->Search(id))
            {
                //find index 
                index = n->index(id);
                n->Delete(index);
            }
            break;
        }

	}while(c != 'E');

     
}
