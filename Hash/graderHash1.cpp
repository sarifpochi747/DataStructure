#include<iostream>
using namespace std;


class Modulo_diviosin
{
    public:
        int n;
        int table_key[1000];
        string table_data[1000];

        Modulo_diviosin(int n)
        {
            this->n = n;
            for(int i=0;i<n;i++)
            {
                table_key[i] = -1;
                table_data[i] = "-";
            }
        }

        // h(x) = (x+i)%n
        void add_modulo_division(int key,string data)
        {
            int address = key%n;
            table_key[address] = key;
            table_data[address] = data;
        }


        string search_modulo_division(int key)
        {
            
            
            int address = (key)%n;
            if(table_key[address] == key)
            {
                return table_data[address];
            }
            else
            {
                return "-";
            }
            
        }

        void Display()
        {
            for(int i=0;i<n;i++)
            {
                cout<<"("<<table_key[i]<<","<<table_data[i]<<") ";
            }
            cout<<endl;
        }
};


int main()
{
    int size;
    char c;
    int key;
    string data;
    cin >> size;
    Modulo_diviosin h1(size);
    do
    {
        cin >> c;
        switch(c)
        {
            case 'a':
                cin >> key;
                cin >> data;
                h1.add_modulo_division(key,data);
                break;

            case 's':
                cin >> key;
                cout<<h1.search_modulo_division(key)<<endl;
                break;

            case 'p':
                h1.Display();
                break;

            default:
                break;
        }
    } while (c!= 'e');
    
};
