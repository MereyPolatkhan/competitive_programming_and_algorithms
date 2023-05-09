#include <iostream>
#include <math.h>

#define ull unsigned long long
#define P 97

using namespace std;

string s;

ull myhash(string t){
    ull h = 0;
    for (int i = 0; i < t.size(); i++) {
        h = h * P + t[i];
    }
    return h;
}

void solve() {
    int cnt = 0;
    int l, r;
    cin >> l >> r;

    string w = s.substr(l - 1, r - l + 1);
    int n = s.size();
    int m = w.size();

    ull hw = myhash(w);
    ull hs = myhash(s.substr(0, m));
   
    ull pm = 1;
    for (int i = 0; i < m - 1; i++)
		pm = pm * P;


    for (int i = 0; i <= n - m; i++) {
        if (hs == hw) {
            cnt++;
        }
        hs = (hs - s[i] * pm) * P + s[i + m];
    }

    cout << cnt << "\n";
    return;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> s;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }


    return 0;
}