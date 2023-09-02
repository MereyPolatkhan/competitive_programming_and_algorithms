#include <bits/stdc++.h>
 
using namespace std; 
 
typedef pair<int, int> pii;

#define ll long long
#define ull unsigned long long
#define pb push_back



void solve() {
    string s;
    cin >> s;
    int cnt1 = 0;
    for (char &c: s) {
        if (c == '1') {
            cnt1++;
        }
    }
    int cnt0 = 0;
    for (char &c: s) {
        if (c == '0') {
            cnt0++;
        }
    }

    int done1 = 0, done0 = 0;
    int ans = INT_MAX;
    for (char &c: s) {
        if (c == '0') {
            done0++;
        }
        else {
            done1++;
        }

        ans = min(ans, min(done0 + (cnt1 - done1), done1 + (cnt0 - done0)));
    }
    cout << min(ans, min(cnt0, cnt1)) << "\n";

}
 
 
int main() {
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
 
    return 0;
}