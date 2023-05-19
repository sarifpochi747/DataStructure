#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    
    public:
        Node(int data)
        {
            this->data = data;
        }
};

class signlylinkedlist
{
    private:
        int size;
        Node *head;

    public:
        signlylinkedlist(int data)
        {
            head = new Node(data);
            head->next = NULL;
            size = 1;
        }

        void Insert(int index,int data)
        {
            if(index >=0 && index <= size)
            {
                if(index == 0)
                {
                    //create object;
                    Node *n = new Node(data);
                    n->next = head;
                    head = n;
                    size ++ ;
                }
                else
                {
                    int ni = 1;
                    for(Node *h=head;h != NULL;h=h->next)
                    {
                        if(ni == index)
                        {
                            //create object;
                            Node *n = new Node(data);
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

        void Delete(int index)
        {
            if(index >= 0 && index <=size && size > 1)
            {
                if(index == 0)
                {
                    head = head->next;
                    size --;
                }
                else
                {
                    int ni =1;
                    for(Node *h=head;h != NULL ;h=h->next)
                    {
                        if(ni == index)
                        {
                            h->next = h->next->next;
                            size--;
                            break;
                        }
                        ni++;
                    }
                }
            }
        }

        void Display()
        {
            for(Node *h=head;h!=NULL;h=h->next)
            {
                cout<<h->data<<" ";
            }
            cout<<endl;
        }

        bool Search(int data)
        {
            for(Node *h=head;h != NULL;h=h->next)
            {
                if(h->data == data)
                {
                    return true; //1
                    
                }
            }
            return false; // 0
        }

};

int main()
{
    signlylinkedlist *l = new signlylinkedlist(1);
    l->Insert(1,2);
    l->Insert(2,3);
    l->Insert(3,4);
    l->Display();
    cout<<l->Search(3)<<"\n";
}