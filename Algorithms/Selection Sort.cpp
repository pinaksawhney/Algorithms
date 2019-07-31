// Selection Sort
// Time O(n^2) Space O(1)

#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &vec){

    for(int i=0;i<vec.size();i++){
        int prev_min = vec[i];
        int ind_min = i;
        for(int j=i+1;j<vec.size();j++){
            if(vec[j]<prev_min){
                prev_min = vec[j];
                ind_min = j;
            }
        }
        int temp = prev_min;
        vec[ind_min] = vec[i];
        vec[i] = temp; 
    }
}


int main(){
    vector<int> vec = {2,7,4,1,5,3};
    selection_sort(vec);
    
    for(auto i: vec)
        cout<<i<<" ";
    
    return 0;
}
