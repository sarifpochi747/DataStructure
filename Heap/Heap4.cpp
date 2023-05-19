#include<iostream>
using namespace std;

class MinHeap
{
    private:
    //declaration array
        int arr[100];

    private:
        MinHeap()
        {
            arr[100] = {0};
        }

        void Insert(int data)
        {
            if(arr[0] < 99)
            {
                arr[0] = arr[0] + 1;
                arr[arr[0]] = data;
                int i = arr[0] / 2;
                int parent = i;
                while (i > 1 && arr[i] < arr[parent]) // i != root Node and arr[Children] > arr[parent]
                {
                    //swap
                    int temp = arr[parent];
                    arr[parent] = arr[i];
                    arr[i] = temp; 
                    i = parent; // index child = index parent
                    parent = i/2;
                }
                
            }
        }

        int Delete()
        {
            if(arr[0] > 0)
            {
                int temp = arr[1];
                arr[1] = arr[arr[0]];
                arr[0] = arr[0] - 1;
                int i = 1;
                while ( i  <= arr[0])
                {
                    int parent = i;
                    int left = 2*i;
                    int right = 2*i + 1;
                    if(left <=arr[0] && arr[left] < arr[parent] && arr[left] < arr[right])
                    {
                        swap(arr[left],arr[parent]);
                        i = left;
                    }
                    else if(right <= arr[0] && arr[right] < arr[parent] && arr[right] < arr[left])
                    {
                        swap(arr[right],arr[parent]);
                        i = right;
                    }
                    else
                    {
                        break;
                    }
                }
                return temp;
            }
            return 0;
        }
        void Display()
        {
            for(int i=1;i<=arr[0];i++)
            {
                cout<<arr[i]<<" "; 
            }
            cout<<"\n";
        }


        void main()
        {
            MinHeap obj;
            obj.Insert(9);
            obj.Insert(10);
            obj.Insert(11);
        };

};





















