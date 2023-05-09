#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


ll eiler(ll n) {
    ll all = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            all = all - (all/i);
        }
    }
    if (n > 1) all = all - (all/n);
    return all;
}

int main() {
    fast;
    // read;
    // write;

 
    ll n;
    cin >> n;   

    if (n == 0 || n == 1) {
        cout << 0;
        return 0;
    }


    ll k = 0;
    for (int i = 2; i <= n; i++) {
        k += eiler(i);
    }    

    cout << k;
    
    
    return 0;
}