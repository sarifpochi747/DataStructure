#include<iostream>
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

        void add_edges(int x,int y,int w)
        {
            edges[x][y] = w;
        }

        int parent[100];
        int  find_parent(int n)
        {
            if(parent[n] == -1)
            {
                return n;
            }
            return find_parent(parent[n]);
        }

        int cycle()
        {
            int s_edges = 0;
            int a_edges[100][2];
            for(int i=0;i<100;i++)
            {
                parent[i] = -1;
            }
            for(int i=0;i<vertex;i++)
            {
                for(int j=i+1;j<vertex;j++)
                {
                    if(edges[i][j] > 0)
                    {
                        a_edges[s_edges][0] = i;
                        a_edges[s_edges][1] = j;
                        s_edges ++;
                    }
                }
            }
            for(int i=0;i<s_edges;i++)
            {
                int x = find_parent(a_edges[i][0]);
                int y = find_parent(a_edges[i][1]);
                if(x == y)
                {
                    return 1;
                }
                if( x== -1)
                {
                    parent[x] = y;
                }
                else
                {
                    parent[y] = x;
                }
            }
            return 0 ;
        }
};

int main()
{
    int num;
    int vertex1;
    int vertex2;
    int weight;
    char c;
    cin>>num;
    Graph g(num);
    do
    {
        cin >> c;
        if(c == 'e')
        {
            cin >> vertex1;
            cin >> vertex2;
            cin >> weight;
            g.add_edges(vertex1,vertex2,weight);
        }
    } while (c != 's');
    //cout<<g.cycle()<<"\n";
    if(g.cycle() == 0)
    {
        cout<<"No Cycle";
    }
    else
    {
        cout<<"Cycle";
    }
}
