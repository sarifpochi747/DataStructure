#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int a[6];
        int front =1;
        int rear = 0;
        int size =4;

    bool isEmpty(){
        // Queue ว่าง
        if(front>rear){
            return true;   
        }
        // Qeueu ไม่เต็ม
        else{
            return false;
        }
    }
    
    bool isFull(){
        // Queue เต็ม
        if(rear == size){
            return true;
        }
        // Queue ไม่เต็ม
        else{
            return false;
        }
    }

    //add data in queue
    void enqueue(int n){
        // ตรวจสอบว่าเต็มไหมถ้าเต็มให้หยุดการทำงาน
        if(isFull() == true){

        }
        //ถ้าไม่เต็มให้ทำงานต่อ
        else{
            rear++;
            a[rear] = n;
        }
    }

    // remove data in queue
    int dequeue(){
        if(isEmpty()==true){

        }
        else{
            int temp = a[front];
            front++; 
            return temp;
        }
        return 0;
    }
    void display(int n){
        for(int i=front; i<=rear;i++){
            cout<<a[i]<<endl;
        }
        cout<<n<<endl;
    }

};

int main(){
    //create obj
    Queue obj;
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.enqueue(6);
    int jack = obj.dequeue();
    obj.enqueue(7);
    obj.display(jack);
}

