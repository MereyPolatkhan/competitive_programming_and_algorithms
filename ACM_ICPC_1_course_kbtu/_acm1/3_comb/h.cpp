#include <bits/stdc++.h>

using namespace std;


int n;

void gen(vector<int> & a, int i) {
    if (i == n) {
        for (int i : a) cout << i << " ";
        cout << "\n";
        return;
    }
    else {
        a[i] = 0;
        gen(a, i + 1);
        a[i] = 1;
        if (i == 0 || a[i - 1] != 1) {
            gen(a, i + 1);
        }
    }
}

int main() {

    cin >> n;

    vector<int> a(n);

    gen(a, 0);



    return 0;
}