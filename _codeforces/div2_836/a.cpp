#include <bits/stdc++.h>

using namespace std;


string s;
void solve() {
    cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    s = s + s1;
    cout << s << "\n";
}

int main() {    

    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}