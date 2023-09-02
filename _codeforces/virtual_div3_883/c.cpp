#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;


void make_pref(vector<ll>& a) {
    for (int i = 1; i < a.size(); i++) {
        a[i] += a[i - 1];
    }
}


int n, m, h;

pii search(vector<ll> & a) {
    ll cnt = 0;
    ll penalty = 0;
    ll j = 0;

    for (int i = 0; i < m; i++) {
        if (a[i] <= h) {
            cnt++;
            penalty += a[i];
        }
        else {
            break;
        }
    }

    return {-cnt, penalty};
}


void solve() {
    cin >> n >> m >> h;

    vector<vector<ll>> a(n, vector<ll> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(all(a[i]));
        make_pref(a[i]);
        // make_pref(a[i]);
    }


    // cout << "a: \n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";

    vector<pair<pii, ll>> b;

    for (int i = 0; i < n; i++) {
        b.pb({search(a[i]), i + 1});
    }

    sort(all(b));

    // cout << "b:\n";
    // for (int i = 0; i < b.size(); i++) {
    //     cout << "cnt: " << b[i].first.first << "  penalty: " << b[i].first.second << "  chelik: " << b[i].second << "\n";
    // }
    // cout << "\n\n";



    ll place = 0;
    for (int i = 0; i < b.size(); i++) {
        place++;
        if (b[i].second == 1) break;
    }

    // cout << "result: " << place << "\n\n";
    cout << place << "\n";
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

