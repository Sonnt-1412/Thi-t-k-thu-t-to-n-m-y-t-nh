#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long MAX, ans;
stack<int> Arr;
long n;   
struct student{
    long x, r, dis;
} st[maxn];
bool comp(student a, student b){
    if(a.x == b.x)  return a.r < b.r;
    return a.x < b.x;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);         
    cin >> n;
    for(long i = 1; i <= n; i++){
        cin >> st[i].x; cin >> st[i].r;
        st[i].dis = st[i].r - st[i].x;
    }
    sort(st + 1, st + n + 1, comp);
    MAX = st[n].r - st[n].x;
    ans = 1;
    Arr.push(st[n].r + st[n].x);
    for(long i = n - 1; i >= 1; i--){
        if(st[i].r - st[i].x > MAX){
            ans++;
            while(!Arr.empty()){
                long u = Arr.top();
                if(u <= st[i].r - st[i].x){
                    Arr.pop();
                    ans--;
                }
                else    break;
            }
            Arr.push(st[i].r - st[i].x);
        } 
        MAX = max(MAX, st[i].r - st[i].x);
    }
    cout << ans;
}