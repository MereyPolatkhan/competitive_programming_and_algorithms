#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0;
        return 0;
    }
    vector<int> res;
    while (true) {
        res.push_back(b);
        if (a == b) {
            break;
        }
        else if (a < b) {
            if (b % 2 == 0)
                b = b / 2;
            else 
                b = b + 1;
        }
        else if (a > b) {
            b = b + 1;
        }
    }
    reverse(res.begin(), res.end());
    cout << res.size() - 1 << "\n";
    for (int i = 1; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}