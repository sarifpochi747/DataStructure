#include<iostream>
using namespace std;


class Node
{
    public:
        int key;
        string data;
        Node *next;
        Node()
        {
            key = -1;
            data = "-";
            next = NULL;
        }
};

class Separate_chaining
{
    public:
        int n;
        Node table[1000];

        //construcor
        Separate_chaining(int size)
        {
            n = size;
            
        }


        //add
        void add_separate_chaining(int key ,string data)
        {
            int j = key % n;
            if(table[j].next == NULL)
            {
                table[j].key = key;
                table[j].data = data;
                table[j].next = new Node();
            }
            else 
            {
                Node *t  = table[j].next;
                while ( t->next !=NULL)
                {
                    t = t->next;
                }

                t->key = key;
                t->data = data;
                t->next = new Node();
                
            }
        }

        string search_separate_chaining(int key)
        {
            int j = key %n;
            if(table[j].key == key )
            {
                return table[j].key,table[j].data;
            }
            else if(table[j].next != NULL)
            {
                Node *t = table[j].next;
                while (t->next != NULL)
                {
                    if(t->key == key)
                    {
                        return t->key,t->data;
                    }
                    t =t->next;
                }
                
            }
            return "-";
        }

        void Display()
        {
            for(int i=0;i<n;i++)
            {
                cout<<"("<<table[i].data<<","<<table[i].key<<") ";
                if(table[i].next != NULL)
                {
                    Node *t = table[i].next;
                    while (t->next != NULL)
                    {
                        cout<<"("<<t->data<<","<<t->key<<") ";
                        t = t->next;
                    }
                }
                cout<<endl;
            }
        }
};


int main()
{
    int size;
    char c;
    int key;
    string data;
    cin >> size;
    Separate_chaining h1(size);
    do
    {
        cin >> c;

        switch(c)
        {
            case 'a':
                cin >> key;
                cin >> data;
                h1.add_separate_chaining(key,data);
                break;
            case 's':
                cin >> key;
                cout<< h1.search_separate_chaining(key)<<endl;
                break;
            case 'p':
                h1.Display();
                break;
            default:
                break;
        }
    } while (c != 'e');
    
}
