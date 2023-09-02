#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> res;

    res.pb(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 1) {
            res.pb(a[i]);        
        }
        else {
            res.pb(1);
            res.pb(a[i]);
        }
             
    }
    cout << res.size() << "\n";
    for (int &i: res) 
        cout << i << " ";
    cout << "\n";
 
}

int main() {   

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "----ans---\n";

    int t = 1;
    cin >> t;
    while (t--) {
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
