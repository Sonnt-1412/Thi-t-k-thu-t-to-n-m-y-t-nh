#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int maxn =1e9;
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 696969, "n");
    inf.readSpace();
    int m = inf.readInt(1, 36363636, "m");
    inf.readEoln();
    for(long i = 1; i <= n; i++){
        int w = inf.readInt(1, m, "w");
        inf.readSpace();
    }
    inf.readEoln();
    for(long i = 2; i <= n; i++){
        int v = inf.readInt(1, i-1, "v");
        inf.readEoln();
    }
    // for (int i = 0; i < m; i++) {
    //     int l = inf.readInt(1, n, "l");
    //     inf.readSpace();
    //     int r = inf.readInt(1, n, "r");
    //     inf.readEoln();
    // }
    inf.readEof();
}
