// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class Stack{
    private:
        int top;
        int arr[5];
        int size =4;

    public :
        // contructor
        Stack(){
            top = 0;
            arr[0] = size;
        }
        // Method isEmpty
        bool isEmpty(){
            if(top == 0){
                return true;
            }else{
                return false;
            }
        }
        //Method isFull
        bool isFull(){
            if(top== size){
                return true;
            }else{
                return false;
            }

        }
        // Method push
        void push(int num){
            if(!isFull()){
                top ++;
                arr[top] = num;
            }else{
                cout<< "Stack Overflow"<<endl;
            }
        }
        // Method pop
        void pop(){
            if(!isEmpty()){
                top --;
                cout << "pop complete"<<endl;
                //return arr[top+1];
            }else{
                cout << "Stack Underflow"<<endl;
            }
        }

        // Method peek
        int peek(){
            if(!isEmpty()){
                return arr[top];
            }else{
                cout<<"Stack Underflow";
            }

        }
        void display(){
            for(int i=top;i>=0;i--){
                cout << arr[i]<<endl;
            }
        }




};

int main(){
    // create obj
    Stack obj;
    obj.push(4);
    obj.push(3);
    obj.push(2);
    obj.display();
    return 0;
}
