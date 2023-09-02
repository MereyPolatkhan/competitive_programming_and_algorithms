#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int it = 0;
void solve() {
    it++;
    int n; ll s, sum = 0;
    cin >> n >> s;
    
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // cout << "ans: ";
    if (sum == s) {
        cout << 0 << "\n";
        return;
    }
    int cnt = 0;

    int i = 0, j = n - 1;
    while (i < j) {
        int l = i, r = j;
        while (l < n and a[l] == 0) 
            l++;
        while (r >= 0 and a[r] == 0) {
            r--;
        }

        if (l - i <= j - r) {
            cnt += l - i;
            i = l;
        }
        else {
            cnt += j - r;
            j = r;
        }


        if (i < n and a[i] == 1) {
            i++;
            cnt++;
            sum -= 1;
        }
        else if (j >= 0 and a[j] == 1) {
            j--;
            cnt++;
            sum -= 1;
        }

        if (sum == s) {
            cout << cnt << "\n";
            return;
        }
    }

    cout << -1 << "\n";

    // cout << "\n\n\n";

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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

