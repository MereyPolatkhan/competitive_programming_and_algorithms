#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define en '\n'
 
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;
    
    int i = 0;
    int cnt = 0;
    while(i < n) {
        while (s[i] == s[i + 1]) {
            i++;
        }
        cnt++;
        i++;
    }   


    cout << a * n + max(n * b, (cnt / 2 + 1) * b) << "\n";
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
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
