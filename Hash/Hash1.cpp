#include<iostream>
#include<math.h>
using namespace std;


    /* 
         Collision Resolution
            -> separate chaining / Open Hashing -> use linkedlist
            -> Open addressing / closing Hashing
                -Linear probing function
                -Quadratic probing function
                -Double Hashing probing function
        Operation of Hash -> Insert , Delete ,Search
        Use Function Modulo Division Method 
            -> add Modulo division
            -> search Modulo division
            -> delete Modulo division

    */

   //OpenAddress Closing Hashing
class OpenAddressing
{

    //Attribute
    public:
        int table_key[100];
        string table_data[100];
        int n; // size
        int r; // prime numer less size จำนวนเฉพาะที่น้อยกว่า size เพื่อใช้ใน -Double Hashing probing function

    //constructor
    public:
        OpenAddressing(int n,int r)
        {
            this->n = n;
            this->r = r; 

            for(int i=0;i<n;i++)
            {
                table_key[i] = -1;
                table_data[i] = "-";
            }
            
        }

        // add Modulo Division method
        void add_modulo_division(int key,string data)
        {
            table_key[key%n] = key; // store key;
            table_data[key%n] = data; // store data
        }

        // search Modulo Division method
        string search_modulo_division(int key)
        {
            if(key== table_key[key%n]) /// check key
            {
                return table_data[key%n];
            }
            else
            {
                return "-";
            }
        }


        // 1- linear probing method formula (x+i)%n i=0,1,2,3,4... 
            //-> add,search 
            //add
        void add_linear_probing(int key,string data)
        {
            for(int i=0;i<n;i++)
            {
                int j = (key + i)%n;
                if(table_key[j] == -1) // isEmpty
                {
                    table_key[j] = key;
                    table_data[j] = data;
                    break;
                }
            }
        }

            //search
        string search_linear_probing(int key)
        {
            for(int i=0;i<n;i++)
            {
                int j = (key +i)%n;
                if(table_key[j] == key) /// check key
                {
                    return table_data[j]; //auto break
                }
                if(table_key[j] == -1)
                {
                    return "-";
                }

            }
            return "-";
        }

        // 2- Quadratic probing method formula (x+i**2)%n // i=0,1,2,3,4....  
            //-> add,search 
            //add
        void add_quadratic_probing(int key,string data)
        {
            for(int i=0;i<n;i++)
            {
                int j= (key + i*i)%n;
                if(table_key[j] == -1) // is Empty
                {
                    table_key[j] = key;
                    table_data[j] = data;
                    break;
                }
            }
        }

        //search
        string search_quadratic_probing(int key)
        {
            for(int i=0;i<n;i++)
            {
                int j= (key + i*i)%n;
                if(table_key[j] == key)
                {
                    return table_data[j];  // auto break;
                }
                else if(table_key[j] == -1)
                {
                    return "-";  // auto break;
                }
            }
            return "-";  // auto break;
        }


        /* 
         2- Double probing method formula   H1(x) = (x%n) 
                                            f(x) = r - (x%r)
                                            Hi(x) = (x + i*fx) % n -> i= 0,1,2,3,4..
        */ 
       //add
        void add_double_probing(int key,string data)
        {
            int fx = r - (key%r);
            for(int i=0;i<n;i++)
            {
                int j = (key + i*fx)%n;
                if(table_key[j] == -1) // isEmpty
                {
                    table_key[j] = key;
                    table_data[j] = data;
                    break;
                }
            }
        }

       //search
        string search_double_probing(int key)
        {
            int fx = r - (key%r);
            for(int i=0;i<n;i++)
            {
                int j = (key + i*fx)%n;
                if(table_key[j] == key)
                {
                    return table_data[j];
                }
                else if(table_key[j] == -1)
                {
                    return "-";
                }
            }
            return "-";
        }

        //Display
        void Display()
        {
            for(int i=0;i<n;i++)
            {
                cout<<"( "<<table_key[i]<<","<<table_data[i]<<" )";
            }
            cout<<endl;
        }

};

///========================================================//

class Node
{
    public:
        int key;
        string data;
        Node *next;

    public:
        //constructor
        Node()    
        {
            key = -1;
            data = "-";
            this->next = NULL;
        }

};



class SeparateChaining
{
    //Attribute
    public:
        int n; // size
        Node table[100];

    public:
        //constructor
        SeparateChaining(int n)
        {
            this->n = n;
        }

        void add(int key,string data)
        {
            int j  = key % n ; // address
            if(table[j].next == NULL) // is Empty
            {
                table[j].key = key;
                table[j].data = data;
                table[j].next = new Node();
            }
            else // if collision 
            {
                //create Node
                Node *t = table[j].next;
                while(t->next != NULL)// Find Null
                {
                    t = t->next;
                }
                t->key = key;
                t->data = data;
                t->next = new Node();
            }
        }


        string search(int key)
        {
            int j = key%n; // Address

            if(table[j].key == key) // check key
            {
                return table[j].data;
            }
            else
            {
                Node *t = table[j].next;
                while (t->next != NULL)
                {
                    if(t->key == key)
                    {
                        return t->data; 
                    }
                    t = t->next;
                }

                return "-";
                
            }
        }

        void Display()
        {
            for(int i=0;i<n;i++)
            {
                cout<<"("<<table[i].key<<","<<table[i].data<<")";
                if(table[i].next != NULL)
                {
                    Node *t = table[i].next;
                    while (t->next != NULL)
                    {
                        cout<<"("<<t->key<<","<<t->data<<")";
                        t = t->next;
                    }
                    
                }

            }
            cout<<endl;
        }
};


int main()
{
    // OpenAddressing
    OpenAddressing h1(13,7);
    // Modulo Division
    h1.add_modulo_division(62,"cat");
    h1.add_modulo_division(77,"bird");
    h1.add_modulo_division(56,"ant");
    h1.add_modulo_division(55,"dog");
    h1.add_modulo_division(132,"fish");
    h1.Display();
    cout<<h1.search_modulo_division(62)<<endl;
    cout<<h1.search_modulo_division(100)<<endl;


    // Separate chaining
    SeparateChaining h5(11);
    h5.add(62,"cat");
    h5.add(77,"bird");
    h5.add(56,"ant");
    h5.add(55,"dog");
    h5.add(132,"fish");
    h5.Display();
    cout<<h5.search(55);
}

/* 

    ( -1,- )( -1,- )( 132,fish )( 55,dog )( 56,ant )( -1,- )( -1,- )( -1,- )( -1,- )( -1,- )( 62,cat )( -1,- )( 77,bird )
    cat
    -
    (77,bird)(55,dog)(132,fish)(56,ant)(-1,-)(-1,-)(-1,-)(-1,-)(-1,-)(62,cat)(-1,-)(-1,-)(-1,-)
    dog

 */