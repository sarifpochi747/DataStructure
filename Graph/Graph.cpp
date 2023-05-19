#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;



/* 

    operation of Graph
    1. add_vertex
    2.add_edges;
    3. delete edges
    4. delete vertex
    5. graph traversal
        5.1 depth first traversal
        5.2 Breadth first traversal
    

 */
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
            //set matrix all value = 0
            for(int i=0;i<vertex;i++)
            {
                for(int j=0;j<vertex;j++)
                {
                    edges[i][j] = 0;
                }
            }
        }

        

        //add_edges
        /* 
            x = จุดเริ่มต้น
            y = จุดปลาย
            w = น้ำหนักของเส้นเชื่อมถ้าไม่มี ให้กำหนด = 1
         */
        void add_edges(int x,int y,int w)
        {
            edges[x][y] = w;
        }

        // การแสดงผล ให้แสดงผลเฉพาะเส้นที่เชื่อมน่ะวิ
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

        //breadth first traversal
        /* 
            start : We start from vertex
            <aside>
        💡 beadth first traversal

            1. เริ่มท่องจากจุดยอดใดๆ นำจุดยอดใส่ใน queue
            2. นำข้อมูลออกจาก queue ข้อมูลที่นำออกกำหนดเป็นจุดค้นหา แล้วกำหนดให้จุดนั้นได้รับการเข้าถึงแล้ว
            3. จุดที่เชื่อมกับจุดค้นหา ให้ใส่เข้าไปใน queue ยกเว้นจุดที่ได้รับการเข้าถึงแล้ว
            4. ถ้า queue  ไม่มีข้อมูล ให้หยุดท่อง ถ้ามีข้อมูลให้ไปทำข้อ 2 ใหม่
            </aside>
         */
        void breadth_first_traversal(int start)
        {
            bool visited_bft[100];  // เก็บค่าที่ได้รับการเข้าถึงแล้ว
            //set default = 0;
            for(int i=0;i<100;i++)
            {
                visited_bft[i] =0;
            }
            visited_bft[start]  =1 ;
            //create queue 
            vector<int> q;
            q.push_back(start); //enqueue
            //เมื่อใน queue ยังมีข้อมูลอยู่
            while (q.empty() == 0)
            {
                start = q.front();
                cout<<start<<" ";
                /* 
                    .begin() จะเป็นการคือค่า iterator ตัวเแรกของที่เก็บข้อมูล
                    .erase(interator pos) เป็นการลบข้อมูลใน iterator ที่ iterator pos
                 */
                q.erase(q.begin());
                for(int i=0;i < vertex;i++)  
                {
                    if(visited_bft[i] == 0 && edges[start][i] > 0)
                    {
                        visited_bft[i] = 1;
                        q.push_back(i);
                    }
                }
            }
            

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


        // การตรวจสอบการเชื่อมต่อของการ หรือ กราฟย่อย
        void sub_graph()
        {
            int num_subGraph = 1; // จำนวนกราฟย่อย
            for(int i=0;i<100;i++)
            {
                visited_dft[i]  = 0;
            }
            for(int i=0;i<vertex;i++)
            {
                if(visited_dft[i] == 0)
                {
                    cout<<"sub_graph = "<<num_subGraph<<": ";
                    sub_depth_first_traversal(i);
                    num_subGraph ++;
                }
                cout<<"\n";
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
                            n_in_degree[k] ++;
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
    Graph g(6);
    g.add_edges(0,1,1);  g.add_edges(1,0,1);
    g.add_edges(0,2,1);  g.add_edges(2,0,1);
    g.add_edges(1,3,1); g.add_edges(3,1,1);
    g.add_edges(2,3,1); g.add_edges(3,2,1);
    g.add_edges(3,4,1); g.add_edges(4,3,1);
    g.add_edges(4,5,1); g.add_edges(5,4,1);
    g.Display();
    g.breadth_first_traversal(1); cout<<endl;
    g.depth_first_traversal(1); cout<<endl;
    g.sub_graph(); cout<<endl;
}