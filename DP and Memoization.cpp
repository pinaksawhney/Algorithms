// Minimum steps to 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Using DP -- bottom to up approach
int getMinimumSteps(int n) {
    int dp[n+1]; dp[0] = -1;
    dp[1] = 0;
    for(int i=2;i<n+1;i++){
        dp[i] = dp[i-1] + 1;
        if(i%2==0)
            dp[i] = min(dp[i],1+dp[i/2]);
        if(i%3==0)
            dp[i] = min(dp[i],1+dp[i/3]);
    }
    return dp[n];
}

// Using Memoization -- top-down approach

int memo[10];

int getMinimumSteps_Memo(int n){
    if(n==1) return 0;
    if(memo[n]!=-1) return memo[n];
    int r = 1+getMinimumSteps_Memo(n-1);
    if(n%2==0)
        r = min(r,1+getMinimumSteps_Memo(n/2));
    if(n%3==0)
        r = min(r,1+getMinimumSteps_Memo(n/3));
    memo[n] = r;
    return r;
}


int main(){
    for (int i=0;i<11;i++){
        memo[i] = -1;
    }
    cout<<getMinimumSteps(10)<<endl;
    cout<<getMinimumSteps_Memo(10);
    return 0;
}
