// Time O(n*logn)
// Space O(1)

#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int> &A,int start, int end){
    // do swaps and return pivot index;
    int pivot = A[end]; int pIndex = start;
    for(int i=start;i<end;i++){
        if(A[i]<=pivot){
            int temp = A[pIndex];
            A[pIndex] = A[i];
            A[i] = temp;
            pIndex+=1;
        }
    }
    int temp = A[pIndex];
    A[pIndex] = A[end] ;
    A[end] = temp;
    return pIndex;
}

void QuickSort(vector<int> &A,int start, int end) {
    if (start < end) {
        int pIndex = Partition(A, start, end);
        // recurse on left and right
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
}



int main(){
    vector<int> vec= {7,2,1,6,8,5,3,4};
    QuickSort(vec,0,7);
    for(auto i:vec)
        cout<<i<<" ";
}
