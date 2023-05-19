#include<iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node *next;

        
    public:
    //constructor
        Node(int data)
        {
            this->data = data;
        }
};

class SinlgyLinkedList
{
    private:
        int size;
        Node *head;
    
    public:
        SinlgyLinkedList(int data)
        {
            head  = new Node(data);
            head->next = NULL;
            size = 1;
        }

        void Insert(int data,int index)
        {
            if(index <= size && index >=0)
            {
                if(index == 0 ) 
                {
                    //create Node
                    Node *n = new Node(data);
                    n->next = head;
                    head = n;
                    size ++;
                }
                else
                {
                    int ni =1;
                    for(Node *h=head;h != NULL;h=h->next)
                    {
                        if(ni == index)
                        {
                            //create Node
                            Node *n = new Node(data);
                            n->next = h->next;
                            h->next = n;
                            size++;
                            break;
                        }
                        ni ++;
                    }
                }
            }
        }


        void Delete(int index)
        {
            if (index >= 1 && index <= size && size > 1)
            {
                if(index == 0)
                {
                    head = head->next;
                    size -- ;
                }
                else
                {
                    int ni = 1;
                    for(Node *h=head;h!= NULL;h=h->next)
                    {
                        if(ni == index)
                        {
                            h->next = h->next->next;
                            size -- ;
                            break; 
                        }
                        ni --;
                    }
                }
            }
        }

        bool Search(int data)
        {
            for(Node *h=head;h!=NULL;h=h->next)
            {
                if(h->data == data)
                {
                    return true;
                    break;
                }
            }
            return false;
        }

        void Display()
        {
            for(Node *h = head;h != NULL;h= h->next)
            {
                cout<<h->data<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    SinlgyLinkedList *l = new SinlgyLinkedList(9);
    l->Display();
    l->Insert(7,1);
    l->Display();
    l->Insert(5,1);
    l->Display();
    l->Insert(6,2);
    l->Display();
    l->Insert(9,1);
    l->Delete(1);
    l->Display();

}