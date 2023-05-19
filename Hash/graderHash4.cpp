#include<iostream>
using namespace std;


class Double_probing
{
    public:
        //attribute
        int n;
        int r;
        int table_key[100];
        string table_data[100];


        //contructor
        Double_probing(int n,int r)
        {
            this->n = n;
            this->r = r;
            for(int i=0;i<n;i++)
            {
                table_key[i] = -1;
                table_data[i] = "-";
            }
        }


        //add
        /* 
            formula f(x) = r - (x%r);
                    Hi(x) = (x - i*f(x))%n
         */
        void add_double_probing(int key,string data)
        {
            int fx = r - (key%r);

            for(int i=0;i<n;i++)
            {
                int j = (key + i*fx)%n;
                if(table_key[j] == -1)
                {
                    table_key[j] = key;
                    table_data[j] = data;
                    break;
                }

            }
        }

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
                if(table_key[j] == -1)
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
    int r;
    char c;
    int key;
    string data;
    cin >> size;
    cin >> r;
    Double_probing h1(size,r);
    do
    {
        cin >> c;
        switch(c)
        {
            case 'a':
                cin >> key;
                cin >> data;
                h1.add_double_probing(key,data);
                break;
            case 's':
                cin >> key;
                cout<< h1.search_double_probing(key)<<endl;
                break;
            case 'p':
                h1.Display();
                break;
            default:
                break;
        }
    } while (c != 'e');
    
}