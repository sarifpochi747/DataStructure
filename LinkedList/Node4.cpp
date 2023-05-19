#include<iostream>
#include<string>
using namespace std;

class Node4{
    //attribute
    public:
        int num;
        string str;
        Node4 *next;
    
    //method
    public:
        //constructor
        Node4(int n,string name)
        {
            this->num = n;
            this->str = name;
        }
};

class SignlyLinkedList{
    //attribute
    public:
        Node4 *head;
        int size;
    
    //method
    public:
        //constructor
        SignlyLinkedList()
        {
            size =0;
        }

        //insert
        void Insert(int n,string name,int i)
        {
            if( i == 0 && size == 0)
            {
                //create head Node
                head =  new Node4(n,name);
                head->next = NULL;
                size = 1;
            }
            else if(i>=0 && i<=size && size != 0)
            {
            //index i == 0
                if(i==0)
                {
                    //create Node
                    Node4 *l = new Node4(n,name);
                    l->next = head;
                    head = l;
                    size++;
                }
                else
                {
                   int  ni = 1;
                    for(Node4 *h=head;h!=NULL;h=h->next)
                    {
                        if(ni == i)
                        {
                            //create object
                            Node4 *l = new Node4(n,name);
                            l->next = h->next;
                            h->next = l;
                            size++;
                            break;
                        }
                        ni++;
                    }
                }
            }
        }
        
        //delete
        void Delete(int i)
        {
            if(i<=size && i>= 0 && size >1)
            {
                
                    //delete index == 0
                    if(i == 0)
                    {
                        head = head->next;
                        size --;
                    }
                    else
                    {
                        int ni = 1;
                        for(Node4 *h=head;h!=NULL;h=h->next)
                        {
                            if(ni ==i)
                            {
                                h->next = h->next->next;
                                size --;
                                break;
                            }
                            ni++;
                        }
                    }

                
            }
        }

    bool search(int n)
    {
        bool temp;
        if( size == 0)
        {
            temp =  false;
            
        }
        else
        {
            for(Node4 *h=head;h != NULL;h=h->next)
            {
                if(h->num == n)
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
        for(Node4 *h = head;h != NULL;h=h->next)
        {
            cout<<h->num<<","<<h->str<<" ";
        }
        cout<<endl;
    }

    int  Index(int n)
    {
        int i =0;
        int temp = i;
        if(size >0)
        {
            for(Node4 *h=head;h!=NULL;h=h->next)
            {
                i++;
                if(h->num == n)
                {
                    temp = i;
                    break;
                }
                else
                {
                    temp =0;
                }
            }

        }
        return temp;
    }

};

int main()
{
    int c;
    int isbn;
    int index;
    string str;
    SignlyLinkedList *l = new SignlyLinkedList();
    do
    {
        cin>>c;
        switch (c)
        {
        case 1:
            cin >> isbn;
            cin >> str;
            cin >> index;
            index  = l->Index(index);
            //cout<<"index: " <<index << "\n";
            if(!(l->search(isbn)))
            {
                l->Insert(isbn,str,index);
                //cout<<"size: "<<l->size<<"\n";
            }
            l->Display();
            break;
        
        case 0:
            cin >> index;
            if((l->search(index)))
            {
                //cout<<"sarif"<<"\n";
                index = (l->Index(index)) - 1;
                //cout<<index<<endl;
                l->Delete(index);
            }
            l->Display();
            break;
        }
    } while (c == 0 || c == 1);
    


}