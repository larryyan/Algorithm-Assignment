#include <bits/stdc++.h>

using namespace std;

int n;

struct matrix {
    int a, b, c, d;
};

matrix fib(int x) {
    if(x == 1) return {1, 1, 1, 0};
    int mid = x / 2;
    matrix temp = fib(mid);
    temp = {(temp.a * temp.a + temp.b * temp.c) % 10000, 
            (temp.a * temp.b + temp.b * temp.d) % 10000, 
            (temp.c * temp.a + temp.d * temp.c) % 10000, 
            (temp.c * temp.b + temp.d * temp.d) % 10000};
    if(x % 2 != 0) temp = {temp.a + temp.b, temp.a, temp.c + temp.d, temp.c};
    return temp;
}

int main() {
    cin >> n;
    cout << fib(n + 1).d << endl;
    return 0;
}