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
    vector<int> cnt(n * 2 + 7, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    int res = 0;
    for (int s = 2; s <= n * 2; s++) {
        int teams = 0;
        for (int first_member = 1; first_member <= s / 2; first_member++) {
            if (first_member + first_member == s) 
                teams += cnt[first_member] / 2;
            else
                teams += min(cnt[first_member], cnt[s - first_member]);
        }
        res = max(res, teams);
    }
    cout << res << "\n";

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

