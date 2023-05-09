#include <bits/stdc++.h>
 
using namespace std;
 
long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}
 
 
void solve() {
    int n; 
    cin >> n;
    long long a[n];
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<int> xes;
    for (int i = 1; i <= 100; i++) {
        if (gcd(a[0] + i, a[1] + i) == 1) {
            xes.push_back(i);
        }
    }
 
    for (int i = 10000; i <= 10000 + 100; i++) {
        if (gcd(a[0] + i, a[1] + i) == 1) {
            xes.push_back(i);
        }
    }
 
    if (xes.size() == 0){
        cout << "NO\n";
        return;
    }
 
    for (auto x: xes) {
        int cnt = 0;
        int jai = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                jai++;
                if (gcd(a[i] + x, a[j] + x) == 1) {
                    cnt++;
                }
            }
        }
        if (cnt == jai) {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
 
 
    return 0;
}