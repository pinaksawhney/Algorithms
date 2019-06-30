#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int dp_editDistance(string &a, string &b){
    int m = a.size(); int n = b.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i]==b[j])
                dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = 1+min(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}



int main() {
    string a; string b;
    cin>>a>>b;
    a = "0"+a;
    b = "0"+b;
    cout<<dp_editDistance(a,b);
}

