#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    public:
        //attribute
        int edges[100][100];
        int vertex;

        //contructor
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


        //breadth first traversal
        void breadth_first_traversal(int start)
        {
            bool visited_bft[100];
            for(int i=0;i<100;i++)
            {
                visited_bft[i] = 0;
            }
            visited_bft[start] = 1;
            //create queue
            vector<int> q;
            q.push_back(start);
            while (q.empty() == 0)
            {
                start = q.front(); 
                cout<<start<<" ";
                q.erase(q.begin()); // pop
                for(int i=0;i<vertex;i++)
                {
                    if(visited_bft[i] == 0 && edges[start][i] > 0)
                    {
                        visited_bft[i] = 1;
                        q.push_back(i);
                    }
                }
            }
            
        }

        //depth first traversal
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
            for(int i=0;i<vertex;i++)
            {
                visited_dft[i] = 0;
            }
            sub_depth_first_traversal(start);
            
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
};

int main()
{
    int num;
    int vertex1;
    int vertex2;
    int weight;
    char c;
    cin >> num;
    Graph g1(num);
    do
    {
        cin>>c;
        switch (c)
        {
            case 'e':
                cin >> vertex1;
                cin >> vertex2;
                cin >> weight;
                g1.add_edges(vertex1,vertex2,weight);
                
                break;
        
            default:
                break;
        }
    } while (c != 's');
    
    do
    {
        cin>>c;
        switch (c)
        {    
        case 'd':
            cin>>vertex1;
            g1.depth_first_traversal(vertex1);
            cout<<"\n";
            break;
        case 'b':
            cin>>vertex1;
            g1.breadth_first_traversal(vertex1);
            cout<<"\n";
            break;

        default:
            break;
        }
       
    } while (c != 'q');
    
    
}
        