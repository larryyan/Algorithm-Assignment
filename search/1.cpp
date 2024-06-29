#include <bits/stdc++.h>

using namespace std;

bool is_prime(int k) {
    if (k < 2) return false;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}

int ans, n;
int a[25];
bool used[25];

void dfs(int k) {
    if(k == n) {
        if(is_prime(a[1] + a[n])) 
            ans ++;
        return;
    }
    for(int i = 2; i <= n; i++) {
        if(!used[i] && is_prime(i + a[k])) {
            used[i] = true;
            a[k + 1] = i;
            dfs(k + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    a[1] = 1;
    used[1] = true;
    dfs(1);
    cout << ans / 2 << endl;
    system("pause");
    return 0;
}