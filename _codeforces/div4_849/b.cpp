#include <bits/stdc++.h>

using namespace std;


void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 0;
    int y = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U') {
            y++;
        }
        else if (s[i] == 'R') {
            x++;
        }
        else if (s[i] == 'D') {
            y--;
        }
        else if (s[i] == 'L') {
            x--;
        }
        if (x == 1 and y == 1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}




int main() {
    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}