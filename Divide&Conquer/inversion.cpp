#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int l;
int a[MAXN];

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int merge(int arr[], int l, int m, int r) {
    int aux[r - l + 1];
    for(int i = l; i <= r; i ++)
        aux[i - l] = arr[i];
    int i = l, j = m + 1, ret = 0;
    for(int k = l; k <= r; k++) {
        if(i > m) {
            arr[k] = aux[j - l];
            j ++;
        }
        else if(j > r) {
            arr[k] = aux[i - l];
            i ++;
        } 
        else if(aux[i - l] <= aux[j - l]) {
            arr[k] = aux[i - l];
            i ++;
        }
        else {
            arr[k] = aux[j - l];
            j ++;
            ret += m - i + 1;
        }
    }
    return ret;
}

int inversionCount(int l, int r) {
    if(l >= r) return 0;
    int m = (l + r) / 2;
    return inversionCount(l, m) + inversionCount(m + 1, r) + merge(a, l, m, r);
}

int main() {
    cin >> l;
    for (int i = 0; i < l; i ++)
        cin >> a[i];
    cout << inversionCount(0, l - 1) << endl;
    return 0;
}