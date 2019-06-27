// Time O(n*logn)
// Space Complexity O(n)

#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &left, vector<int> &right, vector<int> &vec){
    int i{}; int j{}; int k{};
    while(i<left.size() && j<right.size()){
        if(left[i]>right[j]) {
            vec[k] = right[j];
            j++;
        }
        else{
            vec[k] = left[i];
            i++;
        }
        k+=1;
    }
    while(i<left.size()){
        vec[k] = left[i];
        i++; k++;
    }
    while(j<right.size()){
        vec[k] = right[j];
        j++; k++;
    }
}

void Merge_Sort(vector<int> &vec) {
    int n = vec.size();
    if (n < 2)
        return;
    else {
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < n / 2; i++) {
            left.push_back(vec[i]);
        }
        for (int i = n / 2; i < n; i++) {
            right.push_back(vec[i]);
        }

        Merge_Sort(left);
        Merge_Sort(right);
        Merge(left, right, vec);
    }
}

int main(){
    vector<int> vec = {1,4,1,6,8,5,3,7};
    Merge_Sort(vec);
    for(auto i: vec)
      cout<<i<<" ";
}
