#include<bits/stdc++.h>
    using namespace std;

    long long f[100005];
    long long n;
long Recursion(long i){
    if(i == 0)  return 1;
    else        return Recursion(i - 1) + 4 * i;
}
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);
        cin >> n;
        cout << Recursion(n);   
}
// Công thức truy hồi thời gian F(n) = F(n-1) + 4 * n
// Giải công thức Truy hồi: F(n) = F(n - 1) + 4 * n 
//                               = F(n - 2) + 4(n - 1) + 4n 
//                               = F(0) + 2 * n * (n + 1) 
//                               = 1 + 2 * n * (n + 1)      --> O(n)