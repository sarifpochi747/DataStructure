#include<iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *link;
  
  public:
    Node(int n)
    {
      this->data = n;
    }
};


class Stack
{
  public:
    Node *top;

  public:
    Stack()
    {
      top = NULL;
    }

    bool isEmpty()
    {
      return top == NULL;
    }
    void Push(int value)
    {
      //create Node for Stack
      Node *n = new Node(value);
      n->link = top;
      top = n;
    }

    void Pop()
    {
      if(!isEmpty())
      {
        top = top->link;
      }
    }

    void display()
    {
      for(Node *n=top;n!=NULL;n=n->link)
      {
        cout<<n->data<<" ";
      }
    }
};

int main()
{
  //create object;
  Stack *obj = new Stack();
  obj->Push(4);
  obj->Push(3);
  obj->Push(2);
  obj->Push(1);
  obj->Pop();
  obj->display();
}