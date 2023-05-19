#include<iostream>
#include<vector>
using namespace std;

class Graph
{
	public:
		int vertex;
		int edges[100][100];
		Graph(int n)
		{
			vertex = n;
			for(int i=0;i<vertex;i++)
			{
				for(int j=0;j<vertex;j++)
				{
					edges[i][j] = 0;
				}
			}
		}
		
		void add_edges(int x,int y,int w )
		{
			edges[x][y] = w;
			
		}
		
		void display()
		{
			for(int i=0;i<vertex;i++)
			{
				cout<<i<<" :";
				for(int j=0;j<vertex;j++)
				{
					if(edges[i][j] > 0)
					{
						cout<<j<<","<<edges[i][j]<<" ";
					}
				}
				cout<<"\n";
			}
		}
		
		
		void breadth_first_traversal(int start)
		{
			bool visited[100];
			for(int i=0;i<vertex;i++)
			{
				visited[i] = 0;
				
			}
			visited[start] = 1;
			vector<int> q;
			q.push_back(start);
			while(q.empty() == 0)
			{
				start = q.front();
				cout<<start<<" ";
				q.erase(q.begin());
				for(int i=0;i<vertex;i++)
				{
					if(visited[i] == 0 && edges[start][i] > 0)
					{
						visited[i] = 1;
						q.push_back(i);
					}
				}
			}
		}
		
		bool visited_dft[100];
		
		void sub_dft(int start)
		{
			visited_dft[start] = 1;
			cout<<start<<" ";
			for(int i=0;i<vertex;i++)
			{
				if(visited_dft[i] == 0 && edges[start][i] > 0)
				{
					sub_dft(i);
				}
			}
		}
		
		void depth_first_traversal(int start)
		{
			for(int i=0;i<100;i++)
			{
				visited_dft[i] = 0;
			}
			sub_dft(start);
		}
		
		
		void sub_graph()
		{
			int num = 1;
			for(int i=0;i<100;i++)
			{
				visited_dft[i] = 0;
				
			}
			
			for(int i=0;i<vertex;i++)
			{
				if(visited_dft[i] == 0)
				{
					cout<<num<<": ";
					num++;
					sub_dft(i);
				}
			}
		}

};



int main()
{
    Graph g(6);
    g.add_edges(0,1,1);  g.add_edges(1,0,1);
    g.add_edges(0,2,1);  g.add_edges(2,0,1);
    g.add_edges(1,3,1); g.add_edges(3,1,1);
    g.add_edges(2,3,1); g.add_edges(3,2,1);
    g.add_edges(3,4,1); g.add_edges(4,3,1);
    g.add_edges(4,5,1); g.add_edges(5,4,1);
    g.display();
    g.breadth_first_traversal(1); cout<<endl;
    g.depth_first_traversal(1); cout<<endl;
    g.sub_graph(); cout<<endl;
}






