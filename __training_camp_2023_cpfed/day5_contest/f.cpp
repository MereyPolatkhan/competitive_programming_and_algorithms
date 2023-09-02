#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;

set<string> st;
string s, t;
int n, m;

void gen(int i, int j, string temp) {
    if (i == n and j == m) {
        st.insert(temp);
        return;
    }
    if (i < n) {
        temp += s[i];
        gen(i + 1, j, temp);
        temp.pop_back();
    }
    if (j < m) {
        temp += t[j];
        gen(i, j + 1, temp);
        temp.pop_back();
    }

}

void solve() {
    cin >> s >> t;
    n = s.size();
    m = t.size();
    string temp = "";

    int i = 0;
    int j = 0;

    gen(i, j, temp);

    for (const string &s: st) {
        cout << s << "\n";
    }
    cout << "\n";
}   


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
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
        st.clear();
    }

    return 0;
}

