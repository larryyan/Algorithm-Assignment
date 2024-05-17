#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int x;
bool f[MAXN];

int solve(int k) {
    if(k < 4) return 0;
    for(int i = 2; i < k; i ++)
        if(f[i] && f[k - i])
            return solve(k - i * 2) + 1;
}

int main() {
    cin >> x;
    memset(f, true, sizeof(f));
    f[0] = f[1] = 0;    
    for(int i = 2; i * i <= x; i ++)
        if(f[i])
            for(int j = i * i; j <= x; j += i)
                f[j] = false;
    cout << solve(x) << endl;
    return 0;
}