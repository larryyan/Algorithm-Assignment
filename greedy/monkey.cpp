#include <bits/stdc++.h>

using namespace std;

int x, y, z, a;
string s;

int main() {
    cin >> s;
    x = s[0] - '0';
    y = s[1] - '0';
    z = s[3] - '0';
    a = x * 10 + y;
    while(z != 0) {
        a *= 10;
        z --;
    }
    z = a;
    x = 1;
    while(z != 1) {
        z >>= 1;
        x <<= 1;
    }
    cout << 2 * (a - x) + 1 << endl;
    return 0;
}