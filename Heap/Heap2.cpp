#include<iostream>
using namespace std;

class Heap2{
    public:
        int arr[100];
        int size;
    public:
        Heap2() 
        {
            size = 0;
            arr[0] = size;
        }

        void Add(int n)
        {
            size ++;
            arr[size] = n;
            arr[0] = size;
        }

        void Heapify(int i) 
        { 
            int largest = i; // parent 
            int left = 2*i; 
            int right = 2*i + 1; 


            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if(right <= size && arr[right] > arr[largest])
            {
                largest = right; 
            }
            if(largest != i)
            {
                swap(arr[largest],arr[i]); 
                Heapify(largest); 
            }
            
        }

        void InsertHeap(int value)
        {
            size++;
            arr[size] = value;
            arr[0] = size;
            int i =size;
            int parent = i / 2; 
            // เพราะ ถ้า i == 1 parent จะติดลบ
            while(i>1 &&arr[i] > arr[parent] ) // i  != root Node
            {
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;
                i  = parent; // 
                parent = i / 2;
            }  
        }

        void HeapSort()
        {
            // size = 7
            for(int i =size/2;i>=1;i--) // 3,2,1
            {
                Heapify(i);
            }
        }


        int  Delete()
        {
            int i =size;
            int temp = arr[1];
            swap(arr[1],arr[i]);
            size -- ;
            arr[0] = size;
            //เรียงจากบนลงล่าง
            Heapify(1);
            return temp;
        }

        void Display()
        {
            for(int i=0;i<=size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<< endl;
        }
};

int main()
{
    //create object
    Heap2 obj ;
    // add values in array
    /* obj.Add(55);
    obj.Add(14);
    obj.Add(50);
    obj.Add(20);
    obj.Add(5);
    obj.Add(15);
    obj.Add(30);
    obj.Add(31);
    obj.Add(60);
    obj.Add(28);
    obj.HeapSort();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display();
    cout<<obj.Delete()<<": ";
    obj.Display(); */
    obj.InsertHeap(15);
    obj.Display();
    obj.InsertHeap(13);
    obj.Display();
    obj.InsertHeap(9);
    obj.Display();
    obj.InsertHeap(20);
    obj.Display();
    obj.InsertHeap(8);
    obj.Display();
    obj.InsertHeap(11);
    obj.Display();
    obj.InsertHeap(30);
    obj.Display();
    obj.InsertHeap(32);
    obj.Display();
    
    

}