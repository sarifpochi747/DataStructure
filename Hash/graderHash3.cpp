#include<iostream>
using namespace std;


class Quadratic_probing{
    //attribute
    public:
        int n;
        int table_key[100];
        string table_data[100];

        Quadratic_probing(int size)
        {
            n = size;
            for(int i=0;i<n;i++)
            {
                table_key[i] = -1;
                table_data[i] = "-";
            }
        }

        //add data
        //formula h(x) = (x + i^2)%n 
        void add_quadratic_probing(int key ,string data)
        {
            for(int i=0;i<n;i++)
            {
                int j = (key + i*i)%n;
                if(table_key[j] == -1)
                {
                    table_key[j] = key;
                    table_data[j] = data;
                    break;
                }
                
            }
        }

        string search_quadratic_probing(int key)
        {
            for(int i=0;i<n;i++)
            {
                int j = (key +i*i)%n;
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
    Quadratic_probing h1(size);
    do
    {
        cin >> c;
        switch(c)
        {
            case 'a':
                cin >> key;
                cin >> data;
                h1.add_quadratic_probing(key,data);
                break;

            case 's':
                cin >> key;
                cout<<h1.search_quadratic_probing(key)<<endl;
                break;

            case 'p':
                h1.Display();
                break;

            default:
                break;
        }
    } while (c != 'e');
    
}