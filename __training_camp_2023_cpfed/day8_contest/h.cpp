#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;



int opposite(int i, int n) {
    if (n % 2 == 1) {
        int mid = n / 2;
        return mid + (mid - i);
    }
    else {
        return n - 1 - i;
    }

}

void solve() {
    int n, m;
    string s;
    set<pii> bad;

    cin >> n >> m;
    cin >> s;
    
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            bad.insert({i, j});
        }
        i++;
        j--;
    }

    ll cnt = 0;


    for (int k = 0; k < m; k++) {
        int i; char c;
        cin >> i >> c;
        i--;
        s[i] = c;

        int j = opposite(i, n);
        if (i == j) {
            if (bad.size() == 0) {
                cnt++;
            }
            continue;
        }
        if (i > j) swap(i, j);

        if (bad.count({i, j})) {
            if (s[i] == s[j]) {
                bad.erase(bad.find({i, j}));
            }
        }
        else {
            if (s[i] != s[j]) {
                bad.insert({i, j});
            }
        }

        if (bad.size() == 0) {
            cnt++;
        }
    }

    cout << cnt << "\n";
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
    }

    return 0;
}