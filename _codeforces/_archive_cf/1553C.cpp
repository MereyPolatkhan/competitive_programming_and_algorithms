#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


int func(string &s) {
    int a = 0;
    int b = 0;

    // cout << "func: " << s << "\n";
    for (int i = 0; i < 10; i++) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                a++;
            }
            else {
                b++;
            }
        }
        int d = 9 - i;
        int left_a = d / 2, left_b = d / 2;
        if (d % 2 == 1) {   
            left_b++;
        }   
        if (a > left_b + b || b > left_a + a) {
            // cout << "func: " << s << " i: " << i << "\n";
            return i + 1;
        }

        // cout << "i: " << i << " a: " << a << " b: " << b << " left_a: " << left_a << "  left_b: " << left_b << "\n";
    }
    return 10;
}

void solve() {
    string s;
    cin >> s;

    string a = s, b = s;
    for (int i = 0; i < 10; i++) {
        if (s[i] == '?') {
            if (i % 2 == 0) {
                a[i] = '1';
                b[i] = '0';
            }
            else {
                a[i] = '0';
                b[i] = '1';
            }
        }
    }

    // 1?0???1001

    // ababababab
    // 1000101001
    
    // ababababab
    // 1101011001
    // cout << "a: " << a << "\n";
    // cout << "b: " << b << "\n";

    cout << min(func(a), func(b)) << "\n";
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
