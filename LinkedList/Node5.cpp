#include<iostream>
using namespace std;

class Node5{
    //attribute
    public:
        int id;
        Node5 *next;
    
    //method
    public:
        Node5(int n)
        {
            this->id = n;
        }

};

class SinglyLinkedList{
    //attribuute
    public:
        Node5 *head;
        int size;
    
    //method
    public:
        //constructor
        SinglyLinkedList()
        {
            size = 0;
        }
        
        void Insert(int n,int i)
        {
            if(size == 0 && i==0)
            {
                //create head Node
                head = new Node5(n);
                head->next = NULL;
                size = 1;
                //Display();
            }
            else if(i>=0 && i<= size && size != 0)
            {
                if(i == 0)
                {
                    // insert index ==0
                    //create Node
                    Node5 *l = new Node5(n);
                    l->next = head;
                    head = l;
                    size ++;
                }
                else
                {
                    int ni = 1;
                    for(Node5 *h=head;h != NULL;h=h->next)
                    {
                        if(ni == i)
                        {
                            //create Node
                            Node5 *l = new Node5(n);
                            l->next = h->next;
                            h->next = l;
                            size ++;
                            break;
                        }
                        ni ++;
                    }
                }
               // Display();
            }
        }

        void Delete(int i)
        {
            if(i<=size && i>=0 && size >1)
            {
                if(i == 0)
                {
                    head = head->next;
                    size --;
                }
                else
                {
                    int ni =1;
                    for(Node5 *h=head;h!=NULL;h=h->next)
                    {
                        if(ni == i)
                        {
                            h->next = h ->next->next;
                            size --;
                            break;
                        }
                        ni ++;
                    }

                }
                //Display();
            }
        }

        bool Search(int n)
        {
            bool temp;
            if(size == 0)
            {
                temp = false;
            }
            else
            {
                for(Node5 *h=head;h!=NULL;h=h->next)
                {
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

        void Display()
        {
            for(Node5 *h=head;h!=NULL;h=h->next)
            {
                cout<<h->id<<" ";
            }
            cout<<endl;
        }


        int Index(int n)
        {
            int i =0;
            int temp =i;
            if(size >0)
            {
                for(Node5 *h=head;h!=NULL;h=h->next)
                {
                    i++;
                    if( h->id == n)
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
    char c;
    int n;
    int index;
    SinglyLinkedList *l = new SinglyLinkedList();
    do
    {
        cin>>c;
        switch (c)
        {
        case 'a':
            cin>>n;
            cin>>index;
            if(!(l->Search(n)))
            {
                index = l->Index(index);
                l->Insert(n,index);
                //cout<<"size: "<<l->size<<endl;
                //cout<<"index: "<<index<<endl;
            }
            break;

        case 'r':
            cin >> index;
            if(l->Search(index))
            {
                index = l->Index(index);
                l->Delete(index);
            }
            break;
        case 'p':
            l->Display();
            break;
        }


    } while (c != 'e');
    
}
