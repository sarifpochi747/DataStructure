#include<iostream>
using namespace std;

class Node
{
    public:
        int value;
        Node *right;
        Node *left;

        Node(int v)
        {
            value = v;
            this->left = NULL;
            this->right = NULL;
        }
};

class Tree
{
    public:
        Node *rootNode;

        Tree(int value)
        {
            rootNode = new Node(value);
        }

        void add_node(int value)
        {
            Node *n = rootNode;
            while (true)
            {
                if(value < n->value && n->left != NULL)
                {
                    n = n->left;
                }
                else if( value > n->value && n->right != NULL)
                {
                    n = n->right;
                }
                else if( value < n->value && n->left == NULL)
                {
                    n->left = new Node(value);
                    break;
                }
                else if(value > n->value && n->right == NULL)
                {
                    n->right = new Node(value);
                    break;
                }
                else if (value == n->value && n->right != NULL)
                {
                    n->right;
                    break;
                }
                else if (value == n->value && n->right == NULL)
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
        void breadth_first_traversal()
        {
            for(int i=0;i<=height(rootNode->value);i++)
            {
                print_level(rootNode,i);
                cout<<"|";
            }
            cout<<"\n";
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
    int value;
    char c;
    cin >> c;
    cin >> value;
    Tree t1(value);
    do
    {
        cin >>  c;
        switch(c){
            case 'i':
                cin >> value;
                t1.add_node(value);
                break;
            case 'p':
                t1.breadth_first_traversal();
                break;
            
            case 'd':
                cin >> value;
                t1.delete_node(value);
                break;
            default:
                break;
        }

    } while (c != 'x');
    

}