// Moore's Majority Algorithm
// Time O(n) Space O(1)

#include <iostream>
#include <vector>
using namespace std;

int get_majority_candidate(vector<int>vec){
    int candidate = vec[0]; int count = 1;
    for(int i=1;i<vec.size();i++){
        if(count != 0){
        if(vec[i]!=candidate){
            count-=1;
        }
        else{
            count+=1;
        }
        }
        else{
            candidate = vec[i];
            count = 1;
        }
    }
    if(count>0)
        return candidate;
    else
        return -1;
}




int main(){
    int n; cin >> n;
    vector<int> vec(n);

    for (size_t i = 0; i < vec.size(); ++i) {
        cin >> vec[i]; }

    int cand = get_majority_candidate(vec);

    if(cand == -1)
        cout<<0;
    else{
        int  count = 0; int flag = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==cand){
                count+=1;
                if(count>vec.size()/2){
                    cout<<1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag == 0)
            cout<<0;
    }
    return 0;
}

