// Selection Sort
// Time O(n^2) Space O(1)

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        int flag = 0;
        for(int j=0;j<vec.size()-i-1;j++){
            if(vec[j]>vec[j+1]){
                int temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
}


int main(){
    vector<int> vec = {2,7,3,1,5};
    bubble_sort(vec);
    
    for(auto i: vec)
        cout<<i<<" ";
    
    return 0;
}
