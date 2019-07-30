// Binary Min-Heap implementation

#include <iostream>
#include <vector>

using namespace std;


class MinHeap{
    int* h_arr;
    int capacity;
    int heap_size;
public:
    void swap(int* x, int* y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    MinHeap(int capacity){
        heap_size = 0;
        this->capacity = capacity;
        h_arr = new int[capacity];
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    void MinHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size && h_arr[l]<h_arr[smallest])
            smallest = l;
        if(r < heap_size && h_arr[r]<h_arr[smallest])
            smallest = r;
        if(i!=smallest){
            swap(&h_arr[i],&h_arr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin(){
        if(heap_size<=0)
            return INT_MAX;
        if(heap_size==1){
            heap_size--;
            return h_arr[0];
        }
        int root = h_arr[0];
        h_arr[0] = h_arr[heap_size-1];
        heap_size--;
        MinHeapify(0);
        return root;
    }

    void delete_key(int i){
        decrease_key(i, INT_MIN);
        extractMin();
    }

    int getMin(){
        if(heap_size>0)
            return h_arr[0];
        else
            return -1;
    }

    void decrease_key(int i, int new_val){
        h_arr[i] = new_val;
        while(i!=0 && h_arr[parent(i)]>h_arr[i]){
            swap(&h_arr[i],&h_arr[parent(i)]);
            i = parent(i);
        }
    }

    void insert_key(int k){
        if(heap_size==capacity)
            return;
        heap_size++;
        int i = heap_size-1;
        h_arr[i] = k;
        while(i!=0 && h_arr[parent(i)]>h_arr[i]){
            swap(&h_arr[parent(i)],&h_arr[i]);
            i = parent(i);
        }
    }
};


int main(){
    MinHeap h(11);
    h.insert_key(3);
    h.insert_key(2);
    h.delete_key(1);
    h.insert_key(15);
    h.insert_key(5);
    h.insert_key(4);
    h.insert_key(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decrease_key(2, 1);
    cout << h.getMin();
    return 0;
}
