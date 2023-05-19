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
        void Display()
        {
            for(int i=0;i<vertex;i++)
            {
                cout<<i<<": ";
                for(int j=0;j<vertex;j++)
                {
                    if(edges[i][j] > 0)
                    {
                        cout<<j<<","<<edges[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }

        int n_in_degree[100];
        int t_edges[100][100];
        void in_degree()
        {
            for(int i=0;i<vertex;i++)
            {
                n_in_degree[i] = 0;
                for(int j=0;j<vertex;j++)
                {
                    for(int k=0;k<vertex;k++)
                    {
                        if(t_edges[j][k] == 1)
                        {
                            n_in_degree[k] = n_in_degree[k] +1;
                        }
                    }
                }
            }
        }

        void topologicalsort()
        {
            bool visited[100];
            int t_vertex = 0;

            for(int i=0;i<vertex;i++)
            {
                visited[i] = 0;
                for(int j=0;j<vertex;j++)
                {
                    t_edges[i][j] = edges[i][j];
                }
            }
            while(t_vertex < vertex)
            {
                in_degree();
                for(int i=0;i<vertex;i++)
                {
                    if(n_in_degree[i] ==  0 && visited[i] == 0 )
                    {
                        visited[i] = 1;

                        //print
                        cout<<i<<" ";
                        for(int j=0;j<vertex;j++)
                        {
                            t_edges[i][j] = 0;
                        }
                        t_vertex ++;
                        break;
                    }
                }
            }
        }
};

int main()
{
    int vertex1;
    int vertex2;
    int weight;
    int num;
    char c;
    cin >> num;
    Graph g(num);
    do
    {
        cin >> c;
        switch (c)
        {
        case 'e':
            cin>> vertex1;
            cin>> vertex2;
            cin>> weight;
            g.add_edges(vertex1,vertex2,weight);
            break;
        
        default:
            break;
        }
    } while (c != 's');
    g.topologicalsort();
    
}

