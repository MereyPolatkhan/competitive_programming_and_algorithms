#include <bits/stdc++.h>


using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int a = 0, b = n - 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            a = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            b = i;
            break;
        }
    }

    if (a == b) {
        cout << 1 << "\n";
        return;
    }   

    int cnt = 0;
    int i = a; 
    while (i < b) {
        int next = i;
        for (int j = i + 1; j <= b; j++) {
            if (s[j] == '*' and j - i <= k) {
                next = j;
            }
        }
        i = next;
        cnt++;
    }

    cout << cnt + 1 << "\n";


}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}