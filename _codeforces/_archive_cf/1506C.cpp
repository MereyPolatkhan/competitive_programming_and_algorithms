#include <bits/stdc++.h>


using namespace std;

pair<int, int> search(string &b, string &t) {
    for (int i = 0; i < b.size() - t.size() + 1; i++) {
        if (b.substr(i, t.size()) == t) {
            return {i, i + t.size() - 1};
        }
    }
    return {-1, -1};
}

int calc(int i, int j, int n) {
    return i + n - 1 - j;
}

void solve() {
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size()) {
        swap(a, b);
    }

    int res = 1e9;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i; j < a.size(); j++) {
            string t = a.substr(i, j - i + 1);
            pair<int, int> lr = search(b, t);
            if (lr.first == -1 and lr.second == -1) {
                continue;
            }
            res = min(res, calc(i, j, a.size()) + calc(lr.first, lr.second, b.size()));
        }
    }
    if (res == 1e9) 
        cout << a.size() + b.size() << "\n";
    else 
        cout << res << "\n";
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }




    return 0;
}