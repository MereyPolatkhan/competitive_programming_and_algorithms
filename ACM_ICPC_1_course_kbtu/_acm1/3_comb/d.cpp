#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<vector<int>> res;

bool contain(vector<int> & a, int n) {
    for (int i : a) if (i == n) return true;
    return false;
}


void gen(vector<int> & a, int j) {
    if (a.size() == k) {
        // for (int i : a) cout << i << " "; cout << "\n";
        res.push_back(a);
    }
    else {
        for (int i = j; i <= n; i++) {
            if (contain(a, i) == false) {
                a.push_back(i);
                gen(a, i + 1);
                a.pop_back();
            }
        }
        // for (int i : a) cout << i << " "; cout << "\n";
    }
}

int main() {
    // freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);

    cin >> n >> k;

    vector<int> a;

    gen(a, 1);

    int index = 1;
    for (auto i : res) {
        if (index < 10) cout << " ";
        cout << index << " :: ";
        index++;
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}