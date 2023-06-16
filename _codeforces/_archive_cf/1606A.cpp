#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool calc(int &cnt) {
    if (cnt > 0) {
        cnt--;
        return 1;
    }
    return 0;
}

string func(string &s, string t, int cnt) {
    for (int i = 0; i < s.size() - 1; i++) {    
        if (s[i] == t[0] and s[i + 1] == t[1]) {
            if (i == 0) {
                if (calc(cnt)) {
                    s[i] = t[1];
                }
            }
            else {
                if (s[i - 1] != t[1]) {
                    if (calc(cnt)) {
                        s[i] = t[1];
                    }
                }
            }
        }
    }
    return s;
}   


void solve() {
    string s;
    cin >> s;

    int ab = 0;
    int ba = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a' and s[i + 1] == 'b') {
            ab++;
        }
        if (s[i] == 'b' and s[i + 1] == 'a') {
            ba++;
        }
    }

    if (ab == ba) {
        cout << s << "\n";
    }
    else if (ab > ba) {
        cout << func(s, "ab", ab - ba) << "\n";
    }
    else {
        cout << func(s, "ba", ba - ab) << "\n";
    }
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
