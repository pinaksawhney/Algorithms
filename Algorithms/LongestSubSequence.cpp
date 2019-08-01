#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> &vec){
    int dp[vec.size()];
    for(int i=0;i<vec.size();i++)
        dp[i] = 1;
    for(int i=1;i<vec.size();i++){
        for(int j=0;j<i;j++){
            if(vec[j]<=vec[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int max = dp[0];
    for(int i=0;i<vec.size();i++){
        if(dp[i]>=max)
            max = dp[i];
    }
    return max;
}


int main(){
    vector<int> vec = {5,3,4,8,6,7};
    cout<<LIS(vec);
    return 0;
}
