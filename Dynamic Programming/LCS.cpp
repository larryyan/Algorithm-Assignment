#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int dp[MAXN][MAXN];
string x, y;

int main() {
    cin >> x >> y;
    for(int i = 1; i <= x.size(); i ++) {
        for(int j = 1; j <= y.size(); j ++) {
            if(x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[x.size()][y.size()] << endl;
    return 0;
}