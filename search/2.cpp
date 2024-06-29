#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, c, ans;
int w[MAXN], v[MAXN];

struct node {
    int w, v, num;
};

queue<node> q;

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    for (int i = 1; i <= n; i ++)
        cin >> v[i];
    
    q.push({0, 0, 1});

    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (t.num == n + 1) {
            ans = max(ans, t.v);
            continue;
        }
        q.push({t.w, t.v, t.num + 1});
        if (t.w + w[t.num] <= c)
            q.push({t.w + w[t.num], t.v + v[t.num], t.num + 1});
    }
    cout << ans << endl;

    system("pause");
    return 0;
}