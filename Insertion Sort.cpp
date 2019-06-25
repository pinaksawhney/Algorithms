// Insertion Sort
// Time O(n^2) Space O(1)

#include <iostream>
#include <vector>
using namespace std;

void Insertion_sort(vector<int> &vec){

    for(int i=1;i<vec.size();i++){
        int value = vec[i];
        int hole = i;
        while(hole>0 && value<vec[hole-1]){
            vec[hole] = vec[hole-1];
            hole = hole-1;
        }
        vec[hole] = value;
    }
}


int main(){
    vector<int> vec = {99,71,-23,11,-5};
    Insertion_sort(vec);
    
    for(auto i: vec)
        cout<<i<<" ";
    
    return 0;
}
