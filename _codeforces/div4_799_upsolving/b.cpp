#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


void solve() {
    int n;
    cin >> n;


    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    if (n % 2 + st.size() % 2 == 1) {
        cout << st.size() - 1 << "\n";
    }
    else {
        cout << st.size() << "\n";
    }

    

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
