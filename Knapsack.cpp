// implements [0/1] Knapsack solution
#include <iostream>
#include <vector>
using namespace std;

int dp_knapsack(int c, int n, vector<int> wt, vector<int> val){
    vector<int> vec(c+1,0);
    vector<vector<int>> dp(n+1,vec);
    for(int i=0;i<=n;i++) {
        for (int j = 0; j <= c; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(wt[i]<=j)
                dp[i][j] = max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][c];
}

int main() {
  int c{};cin>>c;
  int n{}; cin >>n; vector<int> wt(n+1,0); vector<int> val(n+1,0);
  for(int i=1;i<=n;i++) {
      cin >> wt[i];
      val[i] = wt[i];
  }
  cout<<dp_knapsack(c,n,wt,val);
}
