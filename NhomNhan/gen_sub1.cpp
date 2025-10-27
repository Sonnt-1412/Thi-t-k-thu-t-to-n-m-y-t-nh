#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void genNormalCase() {
    int n= rnd.next(1, 10);
    int m= rnd.next(1, 36);
    cout << n <<" " << m << endl;
    for(int i = 1; i <= n; i++){
        cout << rnd.next(1, m) <<" ";
    }
    cout << endl;
    for(int i = 2; i <= n; i++){
        cout << rnd.next(1, i-1) << endl;
    }
}


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int seed = atoi(argv[2]);
    rnd.setSeed(seed);
    if (type == 1) genNormalCase();
    return 0;
}
