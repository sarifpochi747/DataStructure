#include<iostream>
using namespace std;


class Node2{
    //attribute
    public:
        int data;
        Node2 *next;
        Node2 *prev;
    
    //method
    public:
        //constructor
        Node2(int value)
        {
            this->data = value;
        }
};
class DoubleLinkeList{
    //attribute
    public:
        Node2 *head;
        int size;

    public:
        DoubleLinkeList(int n)
        {
            //begin create head Node ,then point head  to Node
            head = new Node2(n);
            head->next = NULL;
            head->prev = NULL;
            size =1;
        }

        //Insert method
        void Insert(int i,int value)
        {
            if(i>=0 && i<= size)
            {
                // insert index 0
                if( i == 0)
                {
                    //create Node
                    Node2 *n = new Node2(value);
                    n->prev = NULL;
                    n->next = head;
                    head->prev = n;
                    head = n;
                    size++;
                }
                else
                {
                    int ni =1;
                    for(Node2 *h=head;h != NULL;h=h->next)
                    {
                        if(ni == i)
                        {
                            //create Node
                            Node2 *n = new Node2(value);
                            n->prev = h;
                            n->next = h->next;
                            h->next = n;
                            size++;
                            break;
                        }
                        ni++;
                    }
                }
            }
        }

        void Delete(int i)
        {
            if(i>=0 && i<=size && size>1)
            {   
                if(i==0)
                {
                    head = head->next;
                    head->prev = NULL;
                    size--;
                }
                else
                {
                    int ni =1;
                    for(Node2 *h=head;h!=NULL;h=h->next)
                    {
                        if(ni ==i)
                        {
                            h->next->next->prev = h;
                            h->next = h->next->next;
                            size--;
                            break;
                        }
                        ni++;
                    }
                }
            }
        }

        bool Search(int value)
        {
            for(Node2 *h=head;h!=NULL;h = h->next)
            {
                if(h->data == value)
                {
                    return true;
                }
            }
            return false;
        }
        void Display()
        {
            for(Node2 *h=head;h!=NULL;h=h->next)
            {
                cout<<h->data<<" ";
            }
            cout<<"\n";
        }


};

int main()
{
    DoubleLinkeList *l = new DoubleLinkeList(9);
    //l->Display();
    l->Insert(0,10);
    //l->Display();
    l->Insert(2,3);
    l->Insert(3,15);
    l->Display();
    l->Delete(2);
    l->Display();
    l->Insert(3,100);
    l->Display();
    
}