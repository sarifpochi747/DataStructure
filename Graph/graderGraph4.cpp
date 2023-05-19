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

        bool visited_dft[100];
        bool tc[100][100];
        int start_vertex;
        bool first_access;
        void sub_transitive_closure_dft(int start)
        {
            if(first_access > 0)
            {
                visited_dft[start] = 1;
                tc[start_vertex][start] = 1;
            }
            first_access = 1;
            for(int i=0;i<vertex;i++)
            {
                if(visited_dft[i] == 0 && edges[start][i] > 0)
                {
                    sub_transitive_closure_dft(i);
                }
            }
        }


        void transitive_closure_dft()
        {
            for(int i=0;i<vertex;i++)
            {
                for(int j=0;j<vertex;j++)
                {
                    tc[i][j] = 0;
                }
            }

            for(int i=0;i<vertex;i++)
            {
                for(int j=0;j<vertex;j++)
                {
                    visited_dft[j] = false;
                }
                first_access = 0;
                start_vertex = i;
                sub_transitive_closure_dft(start_vertex);
            }

            for(int i=0;i<vertex;i++)
            {
                for(int j=0;j<vertex;j++)
                {
                    cout<<tc[i][j]<<" ";
                }
                cout<<endl;
            }
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
    g.transitive_closure_dft();
}