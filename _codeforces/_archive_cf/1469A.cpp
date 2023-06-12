#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



void solve() {

    string s;
    cin >> s;   

    
    int n = s.size();
    
    if (n % 2 == 1 or s[0] == ')' or s[n - 1] == '(') {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";


}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}