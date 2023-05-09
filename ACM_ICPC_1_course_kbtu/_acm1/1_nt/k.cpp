#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long 

ull power2(ull x, ull mod) {
    ull res = x * x;
    return res;
}

vector<int> bin(ull n) {
    vector<int> a;
    while (n > 0) {
        a.push_back(n % 2);
        n /= 2;
    }
    reverse(a.begin(), a.end());
    return a;
}

void solve(ull base, ull exp, ull mod) {
    vector<int> binary = bin(exp);

    ull x = base;
    
    for (ull i = 1; i < binary.size(); i++) {
        x = power2(x, mod) % mod;
        if (binary[i] == 1) {
            x = (x * base) % mod;
        }   
    }

    cout << x << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    ull a, b, c;
    while (cin >> a >> b >> c){
        solve(a, b, c);
    }


    return 0;
}