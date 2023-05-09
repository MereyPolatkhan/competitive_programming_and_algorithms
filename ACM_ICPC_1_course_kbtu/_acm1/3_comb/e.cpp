#include <bits/stdc++.h>

using namespace std;

int n, k;

bool contain(vector<int> & a, int n) {
    for (int i : a) if (i == n) return true;
    return false;
}


void gen(vector<int> & a, int j) {
    if (a.size() == k) {
        for (int i : a)  cout << i << " "; cout << '\n';
    }
    else {
        for (int i = j; i >= 1; i--) {
            if (contain(a, i) == false) {
                a.push_back(i);
                gen(a, i - 1);
                a.pop_back();
            }
        }
    }
}

int main() {
    freopen("generation.in", "r", stdin);
    freopen("generation.out", "w", stdout);

    cin >> n >> k;

    vector<int> a;

    gen(a, n);

    return 0;
}