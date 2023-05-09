#include <bits/stdc++.h>

using namespace std;

bool contain(vector<int> & a, int n) {
    for (int i : a) if (i == n) return true;
    return false;
}

void perm(vector<int> & a, vector<int> & temp) {
    if (a.size() == temp.size()) {
        for (int i : temp) cout << i << " ";
        cout << "\n";
    }
    else {
        for (int n : a) {
            if (contain(temp, n) == false) {
                temp.push_back(n);
                perm(a, temp);
                temp.pop_back();
            }
        }
    }
}

int main() {

    // freopen("perm.in", "r", stdin);
    // freopen("perm.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a;
    for (int i = 1; i <= n; i++) a.push_back(i);

    vector<int> temp;
    perm(a, temp);
    



    return 0;
}