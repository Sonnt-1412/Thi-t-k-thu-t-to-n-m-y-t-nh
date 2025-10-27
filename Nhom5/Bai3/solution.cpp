#include <bits/stdc++.h>
using namespace std;

int n, m;
int ar[15][15];
bool dp[1 << 15][15];
int trace[1 << 15][15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ar[u - 1][v - 1] = ar[v - 1][u - 1] = 1;
    }

    for (int i = 0; i < n; i++)
        dp[1 << i][i] = true;

    for (int mask = 1; mask < (1 << n); mask++)
        for (int u = 0; u < n; u++) if (dp[mask][u])
            for (int v = 0; v < n; v++)
                if (!(mask & (1 << v)) && ar[u][v]) {
                    dp[mask | (1 << v)][v] = true;
                    trace[mask | (1 << v)][v] = u;
                }

    int full = (1 << n) - 1;
    int endNode = -1;
    for (int i = 0; i < n; i++)
        if (dp[full][i]) { endNode = i; break; }

    if (endNode == -1) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    int mask = full, cur = endNode;
    while (mask) {
        path.push_back(cur + 1);
        int prev = trace[mask][cur];
        mask ^= (1 << cur);
        cur = prev;
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < n; i++)
        cout << path[i] << (i == n - 1 ? '\n' : ' ');
}
