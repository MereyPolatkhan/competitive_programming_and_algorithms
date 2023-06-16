#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int func(string &s, string &t) {
    int cnt = 0;

    int first = (int)t[0] - 48;
    int second = (int)t[1] - 48;

    bool x = false;
    bool y = false;

    for (int i = s.size() - 1; i >= 0; i--) {
        int num = (int)s[i] - 48;

        if (y == false and second == num) {
            y = true;
        }
        else if (y == true and x == false and first == num) {
            x = true;
        }
        else if (x and y) {
            break;
        }
        else {
            cnt++;   
        }
    }

    // cout << "s: " << s << "   t: " << t << "  ";
    // cout << "cnt: " << cnt << "\n";
    return cnt;
}

void solve() { 
    string s;
    cin >> s;

    vector<string> v = {"00", "25", "50", "75"};

    int res = 1e9;

    for (string &t: v) {
        res = min(res, func(s, t));
    }
    cout << res << "\n";
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}