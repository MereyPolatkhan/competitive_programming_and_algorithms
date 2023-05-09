#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int a, b;
    // cin >> a >> b;

    // int n = a / b;

    // vector<string> res;

    int n;
    cin >> n;
    double res = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "sin") {
            res = sin(res);
        }
        if (s == "asin") {
            res = asin(res);
        }
        if (s == "cos") {
            res = cos(res);
        }
        if (s == "acos") {
            res = acos(res);
        }
        if (s == "tan") {
            res = tan(res);
        }
        if (s == "atan") {
            res = atan(res);
        }

    }
    cout << res;

    return 0;
}