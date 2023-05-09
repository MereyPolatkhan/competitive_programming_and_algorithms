#include <bits/stdc++.h>

using namespace std;


int a[100];
int res[100];


int main() {

    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        res[a[i]] = i;
    }

    for (int i = 1; i <= n; i++){ 
        cout << res[i] << " ";
    }

    return 0;
}