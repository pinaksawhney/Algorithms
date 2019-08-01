// To calculate inversion in an array
// Time O(n*logn)

#include <iostream>
#include <vector>
using namespace std;


int Merge(vector<int> &left, vector<int> &right, vector<int> &vec){
    int inversion_count{};
    int i{}; int j{}; int k{};
    while(i<left.size() && j<right.size()){
        if(left[i]>right[j]) {
            vec[k] = right[j];
            inversion_count+=(left.size()-i);
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
    return inversion_count;
}

int Merge_Sort(vector<int> &vec) {
    int inversion_count{};
    int n = vec.size();
    if (n < 2)
        return 0;
    else {
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < n / 2; i++) {
            left.push_back(vec[i]);
        }
        for (int i = n / 2; i < n; i++) {
            right.push_back(vec[i]);
        }

        inversion_count+=Merge_Sort(left);
        inversion_count+=Merge_Sort(right);
        inversion_count+=Merge(left, right, vec);
    }
    return inversion_count;
}

int main(){
    int n{};cin>>n;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    int x = Merge_Sort(vec);
    cout<<x;
}
