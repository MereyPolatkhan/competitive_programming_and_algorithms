#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (n/i);
    }
    return cnt;
}


int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}