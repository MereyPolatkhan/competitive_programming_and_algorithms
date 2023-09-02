#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int ctoi(char c) {
    return (int)c - (int)'0';    
}

void go(int &hh, int &mm, int x) {
    x += mm;
    mm = x % 60;
    hh = (hh + x / 60) % 24;
}

bool check(int &hh, int &mm) {
    return hh / 10 == mm % 10 and hh % 10 == mm / 10;
}

void solve() {
    string s; cin >> s;
    int x; cin >> x;
    int hh = ctoi(s[0]) * 10 + ctoi(s[1]);
    int mm = ctoi(s[3]) * 10 + ctoi(s[4]);

        
    int iter = (int)1e5;
    int ih = hh, im = mm;
    set<pii> cnt;
    while (iter--) {
        if (check(hh, mm)) {
            cnt.insert({hh, mm});
        }
        go(hh, mm, x);
        if (hh == ih and mm == im) {
            break;
        }
    }
    cout << cnt.size() << "\n";
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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

