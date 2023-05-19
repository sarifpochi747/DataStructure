#include<iostream>
#include <stack>
#include<queue>
using namespace std;

queue<int> container;
queue<int> col;
queue<int> temp;
int size= 0;

void push(int x){
    container.push(x);
    col.push(x);
    size++;
}

void pop(){
    int temp;
    temp = container.front();
    container.pop();
    cout << temp << endl;
    col.pop();
    size--;
}

void checkLastElement(){
    cout << col.front() << " ";
    cout << col.back() <<endl;
}

void Print(){
    while(!container.empty()){
        temp.push(container.front());
        container.pop();
    }
    
    while(!temp.empty()){
        int t = temp.front();
        cout << t << " ";
        temp.pop();
        container.push(t);
    }
    cout << endl;
}

void ShowSize(){
    cout << container.size() << endl;
}


int main(){
    char Sign;
    int data;
    while(Sign != 'x'){
        cin >> Sign;
        if(Sign == 'E' || Sign == 'e'){
            cin >> data;
            push(data);
        }
        else if(Sign == 'D' || Sign == 'd'){
            pop();
        }
        else if(Sign == 'S' || Sign == 's'){
            checkLastElement();
        }   
        else if(Sign == 'P' || Sign == 'p'){
            Print();
        }
        else if(Sign == 'N' || Sign == 'n'){
            cout << size << endl;
        }
    }
}