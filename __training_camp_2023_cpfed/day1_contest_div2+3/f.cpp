#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;



int a[1000][1000];
int n;

int func(vector<int> & p) {
    int max_occ = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] > max_occ) {
            max_occ = p[i];
            res = i;
        }
    }
    if (max_occ == 1) {
        return -1;
    }
    return res;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> res(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        vector<int> p(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            p[a[i][j]]++;
        }
        res[i] = func(p);
    }


    vector<bool> used(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (res[i] != -1) used[res[i]] = true;
    }

    // cout << "\nres: ";
    // for (int i = 1; i <= n; i++) {
    //     cout << res[i] << " ";
    // }

    
    // cout << "\nused: ";
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": " << used[i] << ",   ";
    // }

    


    for (int i = 1; i <= n; i++) {
        if (res[i] == -1) {
            for (int j = 1; j <= n; j++) {
                if (used[j] == false) {
                    used[j] = true;
                    res[i] = j;
                    break;
                }
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
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

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

