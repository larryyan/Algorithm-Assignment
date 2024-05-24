#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, k, ans;
int a[MAXN], f[MAXN][MAXN];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        f[1][i] = 1;
    }
    for(int i = 2; i <= n; i ++)
        for(int j = i; j <= n; j ++)
            for(int l = 1; l < j; l ++)
                if(a[l] < a[j])
                    f[i][j] += f[i - 1][l];
    for(int i = 1; i <= n; i ++)
        ans += f[k][i];
    cout << ans << endl;
    return 0;
}