#include<iostream>
using namespace std;

class Hash
{
	public:	
		int n;
		int r;
		int key[100];
		string data[100];
		
		Hash(int size,int prime)
		{
			n = size;
			r= prime;
			for(int i=0;i<n;i++)
			{
				key[i] = -1;
				data[i] = "-";
			}
		}
		
		void add_Linear_probing_function(int k,string d)
		{
			for(int i=0;i<n;i++)
			{
				int j = (k+i)%n;
				if(key[j] == -1)
				{
					key[j] = k;
					data[j] = d;
					break;
				}
			}
		}
		
		
		string search__linear_probing_function(int k)
		{
			for(int i=0;i<n;i++)
			{
				int j = (k+i)%n;
				if(key[j] == k)
				{
					return data[j];
				}
				else if(key[j] == -1)
				{
					return "-";
				}
			}
			return "-";
		}
		
		void display()
		{
			for(int i=0;i<n;i++)
			{
				cout<<"("<<key[i]<<","<<data[i]<<") ";
			}
			cout<<endl;
		}
				
		
		
};


int main()
{
	int n;
	int key;
	string data;
	char c;
	cin>> n;
	Hash h(n,3);
	do
	{
		cin >> c;
		switch(c){
			case 'a':
				cin>>key;
				cin >> data;
				h.add_Linear_probing_function(key,data);
				break;
			case 'p':
				h.display();
				break;
			case 's':
				cin >> key;
				cout<<h.search__linear_probing_function(key)<<"\n";
			default:
				break;
		}
	}while( c != 'e');
}
