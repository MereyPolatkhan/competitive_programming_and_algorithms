#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


void solve() {
    double oa, od, oda, obc;
    cin >> oa >> od >> oda >> obc;

    double ratio = sqrt(obc / oda);
    cout << fixed;
    cout << setprecision(6) << ratio * oa - od << " " << ratio * od - oa << "\n";
}





int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}