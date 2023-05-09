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

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    int left = a[1];
    int right = a[n];
    int i = 2;
    int j = n - 1;
    int sum = 0;

    int l = 0;
    int r = n + 1;

    while (i < j) { 
        if (left == right) {
            sum = left;
            l = i;
            r = j;
            i++;
            j--;
        }
        else if (left < right) {
            left += a[i];
            i++;
        }
        else {
            right += a[j];
            j--;
        }
    }



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
