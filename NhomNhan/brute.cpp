#include<bits/stdc++.h>


using namespace std;
const int nmax = 696969;

int n, m;
int w[nmax+1], par[nmax+1];
long long c[nmax+1];
vector<int> adj[nmax+1];
set<pair<long long, int>> a[nmax+1];


void input(){
  cin >> n >> m;
  for(int i=1;i<=n;++i)
    cin >> w[i];
  
  for(int i=2, x;i<=n;++i){
    cin >> x;
    adj[x].push_back(i); 
    par[i] = x;
  }

  for(int i=1;i<=n;++i)
    c[i] = w[i] + adj[i].size();
}

int ans = 0;


void dfs(int u){
  c[u] = w[u] + adj[u].size()-1;
  for(int &v:adj[u]){
    dfs(v);
    a[u].insert({c[v], v});
  }

  while(a[u].size()){
    auto t = *a[u].begin();
    if(t.first + c[u] >= m) break;
    c[u] += t.first;
    int v = t.second;
    a[u].erase(t);
    // cout << t.first << " " << t.second << endl;
    ++ans;
    if(a[u].size()< a[v].size())
      swap(a[u], a[v]);
    
    for(auto &x:a[v])
      a[u].insert(x);
    a[v].clear();
   
  }
}



void solve(){

  input();
  dfs(1);
  cout<<ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);

  solve();




  return 0;
}