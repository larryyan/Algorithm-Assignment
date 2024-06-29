#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, c;
int w[MAXN], v[MAXN];

int f[MAXN][MAXN];

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    for (int i = 1; i <= n; i ++)
        cin >> v[i];
    
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= c; j ++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i])
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    cout << f[n][c] << endl;

    system("pause");
    return 0;
}