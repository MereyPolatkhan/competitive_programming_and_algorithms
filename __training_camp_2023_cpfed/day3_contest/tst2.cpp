#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n\n";
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
int mx_index = 0, mn_index = 0;
int mx, mn;
int n;


void all_pos(vector<pii> & res, vector<int> a) {
    mx = *max_element(all(a));
    for (int i = 0; i < n; i++) {
        if (mx == a[i]) {
            mx_index = i;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            
        }   
    }


}

void all_neg(vector<pii> & res, vector<int> a) {
    
}

void solve() {
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mx = *max_element(all(a)), mn = *min_element(all(a));
    if (mx == mn) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mx == a[i]) {
            mx_index = i;
        }
        if (mn == a[i]) {
            mn_index = i;
        }
    }

    vector<pii> res;
    if (mx > 0 and mn > 0) {
        all_pos(res, a);
    }
    else if (mx < 0 and mn < 0) {
        all_neg(res, a);
    }
    else {
        if (abs(mx) > abs(mn)) {
            for (int i = 0; i < n; i++) {
                while (a[i] < 0) {
                    a[i] += mx;
                    res.pb({i, mx_index});
                }
            }
            all_pos(res, a);

        }
        else {
            for (int i = 0; i < n; i++) {
                while (a[i] > 0) {
                    a[i] += mn;
                    res.pb({i, mn_index});
                }
            }
            all_neg(res, a);
        }
    }

    cout << res.size() << "\n";
    for (auto &x: res) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }
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

