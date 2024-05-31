#include <bits/stdc++.h>

using namespace std;

struct node {
    int p, d;
};

struct cmp1 {
    bool operator()(node a, node b) {
        return a.d < b.d;
    }
};

struct cmp2 {
    bool operator()(node a, node b) {
        return a.p < b.p;
    }
};


int n, x, y, ans;

priority_queue<node, vector<node>, cmp1> pq1;
priority_queue<node, vector<node>, cmp2> pq2;

int main() {
    cin >> n;
    while(n --) {
        cin >> x >> y;
        pq1.push({x, y});
    }
    for(int i = pq1.top().d; i >= 1; i --) {
        while(!pq1.empty() && pq1.top().d == i) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        if(!pq2.empty()) {
            ans += pq2.top().p;
            pq2.pop();
        }
    }
    cout << ans << endl;
    return 0;
}