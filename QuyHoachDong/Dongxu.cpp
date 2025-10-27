#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e6 + 5;
long long ans = 0, n;
long long F[maxn][3];
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL); 
        cin >> n;
        for(long i = 1; i <= n; i++){
            int x;  cin >> x;
            F[i][0] = max(F[i-1][0], F[i-1][1]);
            F[i][1] = F[i-1][0] + x;
        }
    cout << max(F[n][0], F[n][1]);
}