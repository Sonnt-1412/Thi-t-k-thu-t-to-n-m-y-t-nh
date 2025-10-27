#include<bits/stdc++.h>
using namespace std;
const int maxn = 696969 + 5;   
int w[maxn], c[maxn];
bool Is_Delete[maxn];
int parent[maxn];
int n, m, ans = 0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
int find_parent(int u){   
    if(parent[u] == 0)  return 1;
    if(!Is_Delete[parent[u]])  return parent[u];
    return parent[u] = find_parent(parent[u]);
}
void Delete(int u){  
    int par = find_parent(u);
    if(c[par] + c[u] - 1 <= m){
        ans++;
        Is_Delete[u] = true;
        c[par] = c[par] + c[u] - 1;
        Q.push({c[par], par});
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> n >> m;
    for(long i = 1; i <= n; i++)    cin >> w[i];
    for(long i = 1; i <= n; i++)    c[i] = w[i];
    for(long i = 2; i <= n; i++){
        int pi;
        cin >> pi;
        parent[i] = pi;
        c[pi]++;
    }
    Is_Delete[1] = true;
    for(long i = 2; i <= n; i++){Q.push({c[i], i});}
    while(!Q.empty()){
        pair<int,int> ii = Q.top(); Q.pop();
        if(ii.first != c[ii.second] or Is_Delete[ii.second]) continue; 
        Delete(ii.second);
    }
    // cout << ans; 
}