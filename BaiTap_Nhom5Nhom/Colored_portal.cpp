#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
string a[maxn]; 
long n, q, t;
vector<int> adj[10];
string type[10] = {"BG","BR","BY","GR","GY","RY"};

long search(const vector<int> &lis, long l, long r){
    long ans = 1e9;
    long left_temp = 0;
    long right_temp = lis.size() - 1;

    while(left_temp <= right_temp){
        long mid_temp = (left_temp + right_temp) / 2;
        ans = min(ans, abs(lis[mid_temp] - l) + abs(lis[mid_temp] - r));
        if(lis[mid_temp] > r){
            right_temp = mid_temp - 1;
        }
        else if(lis[mid_temp] < l){
            left_temp = mid_temp + 1;
        }
        else    return abs(r - l);
    }

    left_temp = 0;
    right_temp = lis.size() - 1;

    while(left_temp <= right_temp){
        long mid_temp = (left_temp + right_temp) / 2;
        ans = min(ans, abs(lis[mid_temp] - l) + abs(lis[mid_temp] - r));
        if(lis[mid_temp] > l){
            right_temp = mid_temp - 1;
        }
        else{
            left_temp = mid_temp + 1;
        }
    }

    left_temp = 0;
    right_temp = lis.size() - 1;
    while(left_temp <= right_temp){
        long mid_temp = (left_temp + right_temp) / 2;
        ans = min(ans, abs(lis[mid_temp] - l) + abs(lis[mid_temp] - r));
        if(lis[mid_temp] < r){
            left_temp = mid_temp + 1;
        }
        else{
            right_temp = mid_temp - 1;
        }
    }
    return ans;
}

bool Intersect(string a, string b){
    if(a[0] == b[0])    return true;
    if(a[0] == b[1])    return true;
    if(a[1] == b[0])    return true;
    if(a[1] == b[1])    return true;
    return false;
}
string convert(string x){
    if(x == "GB")   return type[0];
    if(x == "RB")   return type[1];
    if(x == "YB")   return type[2];
    if(x == "RG")   return type[3];
    if(x == "YG")   return type[4];
    if(x == "YR")   return type[5];
    return x;
}
long long Find(long x, long y){
    long ans = 1e9;
    if(Intersect(a[x], a[y])){
        return abs(x-y);
    }   
    for(long i = 0; i <= 1; i++)
    for(long j = 0; j <= 1; j++){
        string z = "";
        z += a[x][i];
        z += a[y][j];
        z = convert(z);
        for(long k = 0; k <= 5; k++){
            if(z == type[k] and adj[k].size()){
                ans = min(ans, search(adj[k], min(x, y), max(x,y)));
            }
        }
    }
    if(ans == 1e9)  return -1;
    return ans;
}
void solve(){
    for(long j = 0; j <= 5; j++)    adj[j].clear();
    cin >> n >> q;
    for(long i = 1; i <= n; i++){
        cin >> a[i];
        for(long j = 0; j <= 5; j++){
            if(a[i] == type[j]){
                adj[j].push_back(i);
            }
        }
    }
    for(long i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;  
        cout << Find(x, y) << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> t;
    while(t--){
        solve();
    }        
}