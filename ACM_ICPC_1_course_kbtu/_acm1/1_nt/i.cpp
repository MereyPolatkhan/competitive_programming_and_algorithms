#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define r freopen("input.txt", "r", stdin)
#define w freopen("output.txt", "w", stdout)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ull poww2(ull x) {
    return x * x;
}

ull func(ull x, ull n){ 
    if (n == 1) {
        return x;
    }
    else if (n == 0) {
        return 1;
    }

    else if (n % 2 == 0) {
        return poww2(func(x, n / 2));
    }
    else {
        return x * poww2(func(x, (n - 1) / 2));
    }
}

int main() {
    fast;
    ull x, n;
    cin >> x >> n;
    cout << func(x, n);
   




    return 0;
}