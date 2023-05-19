#include<iostream>
using namespace std;
class Heap3{
    // attribute
    public:
    //declaration array 
        int arr[10000];
        // declaration size 
        int size;

    //method
    //constructor 
    public:
        Heap3()
        {
            // assign value of variable
            size = 0;
            arr[0] = size;
        }

        void Heapify(int i)
        {
            int largest = i;
            int left = 2 * i;
            int right = 2 * i + 1;


            // if a[childrenLeft] > a[parent]  to do  set larget = left
            if(left <= size && arr[largest] < arr[left])
            {
                largest = left;
            }
            // if a[childrenRight] > a[parent]  to do  set larget = Right
            if(right <= size &&arr[largest] < arr[right])
            {
                largest = right;
            }

             // if  lagest is swapped value
            if(largest != i)
            {
                swap(arr[largest] , arr[i]);
                // when Nodechildren is swapped go to check parent = largest
                Heapify(largest);
            }

        }

        //method Inset Heap
        void InsertHeap(int value)
        {
            if(arr[0] < 9999)
            {
                size ++;
                arr[size] = value;
                arr[0] = size;
                int i = size;
                int parent = i / 2;

                // i must more than 1  becuse if i == 1 parent will be negative
                // arr[i] must more than arr[parent] 
                while (i > 1 && arr[i] > arr[parent])
                {
                    swap(arr[i] , arr[parent]);
                    i = parent;
                    parent = i / 2;
                }
            }
        }

        int Delete()
        {
            int temp = arr[1];
            if(arr[0] >= 1)
            {
                swap(arr[1],arr[size]);
                size --;
                arr[0] = size;
                Heapify(1);
            }
            return temp;
            
        }

        void Display()
        {
            if(arr[0] >= 1)
            {
                for(int i=1;i<=size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }

};

int  main()
{
    Heap3 h;
    char c;
    int num;
    do
    {
        cin>> c;
        switch (c)
        {
        case 'a':
            cin>> num;
            h.InsertHeap(num);
            break;
        case 'd':
            if(h.size >=1)
            {
                cout<<h.Delete()<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
            break;
        case 'p':
            h.Display();
            break;
        }
    } while (c != 'e');
}    

    