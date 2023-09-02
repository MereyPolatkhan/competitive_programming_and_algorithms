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

    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (i < cnt0 && s[i] == '1') {
            a.push_back(i + 1);
        }
        else if (i >= cnt0 and s[i] == '0') {
            a.push_back(i + 1);
        }
    }
    if ((int)a.size()) {
        cout << 1 << "\n";
    }
    cout << a.size() << " ";
    for (int &i: a) cout << i << " ";
    cout << "\n";

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
