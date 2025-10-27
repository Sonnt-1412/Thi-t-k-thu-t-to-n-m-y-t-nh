#include<bits/stdc++.h>
using namespace std;

const int maxn = 696969 + 6;    
vector<int> adj[maxn];
long long c[maxn];

int n, m, ans;
int w[maxn];

bool cmp(int a, int b){
    return c[a] <= c[b];
}
void solve(long u){ 
    for(long j = 0; j < adj[u].size(); j++){
        int v = adj[u][j];
        if(adj[v].size() > 0)   solve(v);
    }
    sort(adj[u].begin(), adj[u].end(),cmp);
    for(long j = 0; j < adj[u].size(); j++){
        int v = adj[u][j];
        if(c[u] + c[v] - 1 <= m){
            c[u] = c[u] + c[v] - 1;
            ans++;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(long i = 1; i <= n; i++)    cin >> w[i];
    for(long i = 2; i <= n; i++){
        int pi; cin >> pi;
        adj[pi].push_back(i);
    } 
    for(long i = 1; i <= n; i++){c[i] = w[i] + adj[i].size();}
    solve(1);
    cout << ans;

}