#include <bits/stdc++.h>


using namespace std;

long long n, x, y;

bool check(long long & cnt) { 
    return cnt / x + cnt / y >= n - 1;
}

int main() {

    cin >> n >> x >> y;

    long long l = 0, r = max(x, y) * (n - 1);

    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (check(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << r + min(x, y);




    return 0;
}