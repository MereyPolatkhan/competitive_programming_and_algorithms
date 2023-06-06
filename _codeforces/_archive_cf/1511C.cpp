#include <bits/stdc++.h>



using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> c(51, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (c[a[i]] == -1) c[a[i]] = i;
    }

    while (q--) {
        int t;
        cin >> t;
        int pos = c[t];
        cout << pos << " ";
        for (int i = 1; i <= 50; i++) {
            if (c[i] != -1 and c[i] < pos) {
                c[i]++;
            }
        }
        c[t] = 1;
    }

    return 0;
}