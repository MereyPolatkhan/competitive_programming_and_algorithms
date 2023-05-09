#include <bits/stdc++.h>

using namespace std;




void solve() {






    int n;
    cin >> n;

    string s;
    cin >> s;



    int i = 0;
    int j = n - 1;

    while (i < j) {
        if ((s[i] == '0' and s[j] == '1') or (s[i] == '1' and s[j] == '0')) {
            i++;
            j--;
            n = n - 2;
        }
        else {
            break;
        }
    }

    // cout << s << "    i = " << i << "   j = " << j << "   n = " << n << "\n";
    cout << n << "\n";
}




int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}