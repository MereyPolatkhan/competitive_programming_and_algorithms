#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;




vector<int> a[10007];


bool check(int v) {
    if (a[v].size() == 0) {
        return true;
    }
    int cnt = 0;
    for (int &x: a[v]) {
        if (a[x].size() == 0) {
            cnt++;
        }
    }
    return cnt >= 3;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        a[p].pb(i);
    }

    bool flag = true;

    for (int i = 1; i <= n; i++) {
        if (!check(i)) {
            flag = false;
        }
    }
    if (flag)
        cout << "YES\n";
    else {
        cout << "NO\n";
    }
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
    solve();

    return 0;
}

