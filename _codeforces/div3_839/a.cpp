#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int a = int(s[0] - '0');
    int b= int(s[2] - '0');
    cout << a + b << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}