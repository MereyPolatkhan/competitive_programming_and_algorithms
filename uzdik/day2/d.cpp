#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool check(string &s) {
    if (s.size() == 0) {
        return true;
    }    
    for (int i = 0; i < s.size() - 1; i++) {
        if ((s[i] == 'R' and s[i + 1] == 'B') || (s[i] == 'B' and s[i + 1] == 'R')) {
            return true;
        }
    }
    return false;
}



void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> a;
    string temp = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != 'W') {
            temp += s[i];
        }   
        else {  
            a.pb(temp);
            temp = "";
        }
    }
    a.pb(temp);
    for (auto i: a) {
        if (!check(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

/*  things to check:
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

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

