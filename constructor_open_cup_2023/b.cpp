#include <bits/stdc++.h>

using namespace std;

void solve() {

    string s;
    cin >> s;


    int x = 0, y = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            x++;
        }
        else if (s[i] == 'L') {
            x--;
        }
        else if (s[i] == 'D') {
            y--;
        }
        else if (s[i] == 'U') {
            y++;
        } 
    }


    cout << abs(x) + abs(y) << "\n";

}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}