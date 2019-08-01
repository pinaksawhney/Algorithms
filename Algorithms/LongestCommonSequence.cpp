// calculate longest common sequence between 3 array of numbers.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


long long lcs(long long a[], long long b[], long long c[], int m, int n, int o){

    long long dp[m+1][n+1][o+1];

    for(int i=0;i<=m;i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= o; k++)
                dp[i][j][k] = 0;
        }
    }

    for(int i=0;i<=m;i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (i == 0 || j == 0 || k==0)
                    dp[i][j][k] = 0;

                else if (a[i] == b[j] && b[j]==c[k])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k-1];

                else {
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[m][n][o];
}



int main() {
    int m{}; cin>>m; long long a[m+1];
    a[0] = 0;
    for(int i=1;i<=m;i++)
        cin>>a[i];

    int n{}; cin>>n; long long b[n+1];
    b[0] = 0;
    for(int j=1;j<=n;j++)
        cin>>b[j];

    int o{}; cin>>o; long long c[n+1];
    c[0] = 0;
    for(int k=1;k<=o;k++)
        cin>>c[k];

    cout<<lcs(a,b,c,m,n,o);
    return 0;
}

