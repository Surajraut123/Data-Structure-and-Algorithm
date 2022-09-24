#include<bits/stdc++.h>
using namespace std;

class heap {
    public:
    int n;
    int arr[100];
    int size;
    

    heap() {
        arr[0] = -1;
        size = 0;
    }


    //Step1 - Insert new element in last index of array;
    //Step2 - Find its correct position, with checking its parent 
    //        parent = index/2; 
    //Implementing maxHeap - i.e its parent is always greater than both child elements.
    void insert(int val) {
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index > 1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }


    // Step1 = replace last element with element want to delete.
    // Remove last element i.e decrease size of array by 1;
    //Propagate root node to its correct position

    void deleteElement() {
        if(size==0) {
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i=1;
        while(i<size) {
            int left = 2*i;
            int right = 2*i+1;

            if(left < size && arr[left] > arr[i]) {
                swap(arr[left], arr[i]);
                i = left;
            }
            else if(right < size && arr[right] > arr[i]) {
                swap(arr[right], arr[i]);
                i=right;
            }
            else{
                return;
            }
        }
    }

    void print() {
        for(int i=1;i<=size;i++) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }


    //Convert the given elements into a heap - 
    // i.e Complete Binary Tree
    // In Complete Binary Tree the leaf nodes is present in array in the range of
    // ((n/2) + 1)/2 to nth index
    //We have to process from 1 to n/2 th index.
    //Because a leaf Node is Always Complete Binary Tree. No need to traverse.

    //We given an Rndom Array we have convert it into an heap;

    void heapify(int arr[], int n, int index) {
        int largest = index;
        int left = 2*index;
        int right = 2*index+1;

        if(left <= n && arr[largest] < arr[left]) {
            largest = left;
        }

        if(right <= n && arr[largest] < arr[right]) {
            largest = right;
        }

        if(largest!=index) {
            swap(arr[largest], arr[index]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        int size = n;
        while(size>1) {
            swap(arr[size], arr[1]);
            size--;
            heapify(arr, size, 1);
        }
    }
};


int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    
    cout<<"Inserted Element in Heap" <<endl;
    h.print();

    h.deleteElement();
    cout<<"Deleted root Element in Heap" <<endl;
    h.print();


    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr)/sizeof(arr[0]) -1;
    for(int i=n/2;i>0;i--) {
        h.heapify(arr, n, i);
    }

    cout<<"Heapify Algorithm" <<endl;
    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    h.heapSort(arr, n);
    cout<<"Heap Sort" <<endl;
    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}