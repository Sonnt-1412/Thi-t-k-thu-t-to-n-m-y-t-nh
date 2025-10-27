#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e3 + 5;
int w[maxn], v[maxn];   
long long dp[maxn][100005]; 
int n, m;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(long i = 1; i <= n; i++)    cin >> w[i];
    for(long i = 1; i <= n; i++)    cin >> v[i];
    for(long i = 1; i <= n; i++)
    for(long j = 1; j <= m; j++){
        if(w[i] > j){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            continue;
        }
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
    }
    cout << dp[n][m];

}