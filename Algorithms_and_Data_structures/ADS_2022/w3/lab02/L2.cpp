#include <bits/stdc++.h>

using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}

void p_f(int a[], int n) {
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
}

int main() {

    int n;
    cin >> n;
    int pf[n];
    for (int i = 0; i < n; i++) {
        cin >> pf[i];
    }

    p_f(pf, n);
    
    // print(pf, n);

    int ans = -1e7;
    for (int i = n - 1; i > 0; i--) {
        int mx = pf[i];
        for (int j = i - 1; j > 0; j--) {
            int d = pf[i] - pf[j];
            mx = max(mx, d);
        }
        ans = max(ans, mx);
    }

    cout << ans;
    
    return 0;
}