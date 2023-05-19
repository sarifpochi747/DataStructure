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

        void add_edges(int x,int y ,int w)
        {
            edges[x][y] = w;
        }

        bool visited_dft[100];
        void sub_depth_first_traversal(int start)
        {
            cout<<start<<" ";
            visited_dft[start] = 1;
            for(int i=0;i<vertex;i++)
            {
                if(visited_dft[i] == 0 && edges[start][i] > 0)
                {
                    sub_depth_first_traversal(i);
                }
            }
            
        }

        void depth_first_traversal(int start)
        {
            for(int i=0;i<100;i++)
            {
                visited_dft[i] = 0;
            }
            sub_depth_first_traversal(start);
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
                if(visited_dft[i] ==0)
                {
                    sub_depth_first_traversal(i);
                    cout<<endl;
                    num++;
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
            cin >> vertex1;
            cin >> vertex2;
            cin >> weight;
            g.add_edges(vertex1,vertex2,weight);
            break;
        
        default:
            break;
        }
    } while (c != 's');

    g.sub_graph();
    
}