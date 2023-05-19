#include<iostream>
using namespace std;

        /* 
           Operation of Tree
                -Search
                -Add -> ห้าม add ตัวซ้ำ
                -Delete
                -Traversal
                    -Depth First traversal
                    -Breadth First traversal
                -Depth ปมนั้น ถึงปมราก
                -Height ปมนั้น ถึงปมใบ
         */

        /* 
            search binary tree
             start search at rootNode 
             
         */ 

class Node
{
    public:
        int value;
        Node *left;
        Node *right;

        Node(int value)
        {
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
};

class Tree
{
    public:

        //Attribute
        Node *rootNode;

        //constructor
        Tree(int value)
        {
            rootNode = new Node(value);
        }


        bool search_node(int value)
        {
            Node *n = rootNode;
            while (true)
            {
                if(n->value == value)
                {
                    return true;
                }
                else if (value < n->value && n->left != NULL)
                {
                    n = n->left;
                }
                else if(value > n->value && n->right != NULL) 
                {
                    n = n->right;
                }
                else
                {
                    return false;
                }
            }
            
        }

        //add Node 
        // find the correct location start find at root node

        void add_node(int value)
        {
            Node *n = rootNode;
            while (true)
            {
                if(value < n->value && n->left != NULL)
                {
                    n = n->left;
                }
                else if (value > n->value && n->right != NULL)
                {
                    n = n->right;
                }
                else if (value < n->value && n->left == NULL)
                {
                    n->left = new Node(value);
                    break;
                }
                else if (value > n->value && n->right == NULL)
                {
                    n->right = new Node(value);
                    break;
                }
                else
                {
                    break;
                }
                
            }
            
        }
        // t->l->r use recursive
        void preorder_traversal(Node *n)
        {
            if(n != NULL)
            {
                cout << n->value << ",";
                preorder_traversal(n->left);
                preorder_traversal(n->right);
            }
        }

        //left -> right -> top 
        void posorder_traversal(Node *n)
        {
            if(n != NULL)
            {
                posorder_traversal(n->left);
                posorder_traversal(n->right);
                cout<< n->value <<",";
            }
        }

        // left -> top -> right
        void inorder_traversal(Node *n)
        {
                if(n != NULL)
                {
                    inorder_traversal(n->left);
                    cout<<n->value<<",";
                    inorder_traversal(n->right);
                }
        }

        void print_level(Node *n,int level)
        {
            if(level ==0)
            {
                cout<<n->value<<",";
            }
            else
            {
                if(n->left != NULL)
                {
                    print_level(n->left,level-1);
                }
                if(n->right != NULL)
                {
                    print_level(n->right,level-1);
                }
            }
        }

        void breadth_first_traversal()
        {
            for(int i=0;i<=height(rootNode->value);i++)
            {
                print_level(rootNode,i);
                cout<<"|";
            }
            cout<<"\n";
        }
        int depth(int value)
        {
            int d =0;
            Node *n = rootNode;
            while (true)
            {
                if(value < n->value && n->left != NULL)
                {
                    n = n->left;
                    d++;
                }
                else if(value > n->value && n->right != NULL)
                {
                    n = n->right;
                    d++;
                }
                else if(value == n->value)
                {
                    return d;
                }
                else 
                {
                    return -1;
                }
            }
            
        }

        int h=0;
        int t_h = -1;
        void h_height(Node *n)
        {
            if(n !=NULL)
            {
                t_h ++ ;
                h_height(n->left);
                h_height(n->right);
                if(t_h > h)
                {
                    h = t_h;
                }
                t_h --;
            }
        }
        int height(int value)
        {
            Node *n = rootNode;
            while (true)
            {
                if(value < n->value && n->left !=NULL)
                {
                    n = n->left;
                }
                else if(value > n->value && n->right != NULL)
                {
                    n = n->right;
                }
                else if(value == n->value)
                {
                    h=0;
                    t_h = -1;
                    h_height(n);
                    return h;
                }
                else
                {
                    return -1;
                }
            }
            
        }
        //Delete
        /* 
            1 - delete leaftNode
            2- delete 1 child
            3- delete 2 child
            4- delete rootNode

         */

        void delete_node_child(Node *n)
        {
            if(n->right->left ==NULL)
            {
                int temp_value = n->right->value;
                delete_node(temp_value);
                n->value = temp_value; 
            }
            else
            {
                Node *tn = n->right;
                while (true)
                {
                    if(tn->left == NULL)
                    {
                        break;
                    }
                    tn = tn->left;
                }
                int temp_value = tn->value;
                delete_node(temp_value);
                n->value = temp_value;
                
            }
        }
        void delete_node(int value)
        {
            if(search_node(value))
            {
                //delete rootNode
                if(rootNode->value == value && rootNode->left == NULL && rootNode->right == NULL)
                {
                    // do nothing
                    return;
                }
                else if( rootNode->value == value && rootNode->left != NULL && rootNode->right == NULL)
                {
                    //swap rootNode
                    rootNode = rootNode->left;
                }
                else if(rootNode->value == value && rootNode->left == NULL && rootNode->right != NULL)
                {
                    //swap rootNode
                    rootNode = rootNode->right;
                }
                else if(rootNode->value == value && rootNode->left != NULL && rootNode->right != NULL)
                {
                    //call delete child
                    delete_node_child(rootNode);
                }
                else
                       // is Not root Node
                {
                    Node *n = rootNode;
                    while (true)
                    {
                        if(value < n->value && n->left != NULL)
                        {
                            Node *c = n->left;
                            if(value == c->value)
                            {
                                // delete leaft Node
                                if(c->left == NULL && c->right == NULL)
                                {
                                    n->left = NULL;
                                    break;
                                }
                                //delete  have child left
                                else if(c->left != NULL && c->right == NULL)
                                {
                                    n->left = c->left;
                                    break;
                                }
                                //delete  have child right
                                else if(c->left == NULL && c->right != NULL)
                                {
                                    n->left = c->right;
                                    break;
                                }
                                //delete  have 2 child right left
                                else if(c->left != NULL && c->right != NULL)
                                {
                                    //call fuction 
                                    delete_node_child(c);
                                    break;
                                }
                            }
                             n = n->left;
                        }
                        else if(value > n->value && n->right != NULL)
                        {
                            Node *c = n->right;
                            if(value == c->value)
                            {
                                if(c->left  == NULL && c->right ==NULL)
                                {
                                    n->right = NULL;
                                    break;
                                }
                                else if(c->left != NULL && c->right == NULL)
                                {
                                    n->right = c->left;
                                    break;
                                }
                                else if(c->left == NULL && c->right != NULL)
                                {
                                    n->right = c->right;
                                    break;
                                }
                                else if(c->left !=NULL && c->right != NULL)
                                {
                                    //cal fucntion delete 2 chiledren
                                    delete_node_child(c);
                                    break;
                                }
                            }
                            n = n->right;
                        }
                    }
                }
            }
        }
};


int main()
{
    Tree t1(20);
    t1.breadth_first_traversal();
    t1.add_node(10);
    t1.breadth_first_traversal();
    t1.add_node(5);
    t1.breadth_first_traversal();
    t1.add_node(30);
    t1.breadth_first_traversal();
    t1.add_node(5);
    t1.breadth_first_traversal();
    t1.add_node(15);
    t1.breadth_first_traversal();
    t1.add_node(25);
    t1.breadth_first_traversal();
    t1.add_node(35);
    t1.breadth_first_traversal();
    t1.add_node(12);
    t1.breadth_first_traversal();
    t1.add_node(17);
    t1.breadth_first_traversal();
    /* cout<<t1.search_node(11)<<"\n";
    cout<<t1.search_node(12)<<"\n";
    cout<<t1.height(20)<<endl;
    cout<<t1.height(15)<<endl;
    cout<<t1.depth(20)<<"\n";
    cout<<t1.depth(15)<<"\n";
    t1.preorder_traversal(t1.rootNode); cout<<"\n";
    t1.posorder_traversal(t1.rootNode); cout<<"\n";
    t1.inorder_traversal(t1.rootNode);  cout<<"\n";
    t1.delete_node(25);
	t1.breadth_first_traversal();
	t1.delete_node(30);    
	t1.breadth_first_traversal();
	t1.delete_node(10);
	t1.breadth_first_traversal();
    t1.delete_node(12);
	t1.breadth_first_traversal();
    t1.delete_node(15);  
	t1.breadth_first_traversal();
	t1.delete_node(17);
	t1.breadth_first_traversal();
	t1.delete_node(20);  
	t1.breadth_first_traversal();
	t1.delete_node(20);
	t1.breadth_first_traversal();
	t1.delete_node(35);
	t1.breadth_first_traversal();
	t1.delete_node(5);
	t1.breadth_first_traversal(); */


    /* 
    
    20,|
20,|10,|
20,|10,30,|
20,|10,30,|5,|
20,|10,30,|5,15,|
20,|10,30,|5,15,25,|
20,|10,30,|5,15,25,35,|
20,|10,30,|5,15,25,35,|12,|
20,|10,30,|5,15,25,35,|12,17,|
0
1
3
1
0
2
20,10,5,15,12,17,30,25,35,
5,12,17,15,10,25,35,30,20,
5,10,12,15,17,20,25,30,35,
20,|10,30,|5,15,35,|12,17,|
20,|10,35,|5,15,|12,17,|
20,|12,35,|5,15,|17,|
20,|15,35,|5,17,|
20,|17,35,|5,|
20,|5,35,|
35,|5,|
35,|5,|
5,|
5,|
    
     */
}
