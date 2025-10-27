#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e2 + 5;

ll n, ans = -36;
ll dp_negative[maxn], dp_positive[maxn];
struct solider{
    ll age, intel, power;
}   a[maxn];
bool comp(solider x, solider y){
    if(x.age == y.age)  return x.intel < y.intel;
    return x.age < y.age;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for(long i = 1; i <= n; i++)    cin >> a[i].age >> a[i].intel >> a[i].power;
    for(long i = 1; i <= n; i++)    dp_negative[i] = 1e18, dp_positive[i] = -1e18;
    sort(a + 1, a + n + 1, comp);
    for(long i = 1; i <= n; i++){
        if(a[i].power < 0)  dp_negative[i] = a[i].power;
        else                dp_positive[i] = a[i].power;
        for(long j = i - 1; j >= 1; j--){
            if(a[i].intel >= a[j].intel){
            if(dp_negative[j] != 1e18){
                if(dp_positive[j] != -1e18){
                    dp_negative[i] = min(dp_negative[i],min(a[i].power * dp_negative[j], a[i].power * dp_positive[j]));
                    dp_positive[i] = max(dp_positive[i],max(a[i].power * dp_negative[j], a[i].power * dp_positive[j]));
                }
                else{
                    dp_negative[i] = min(dp_negative[i],a[i].power * dp_negative[j]);
                    dp_positive[i] = max(dp_positive[i],a[i].power * dp_negative[j]);
                }
            }
            else{
                if(dp_positive[j] != -1e18){
                dp_negative[i] = min(dp_negative[i],a[i].power * dp_positive[j]);
                dp_positive[i] = max(dp_positive[i],a[i].power * dp_positive[j]);
                }
            }
        }
    }
}
    for(long i = 1; i <= n; i++)    ans = max(ans, dp_positive[i]); 
    cout << ans;
}