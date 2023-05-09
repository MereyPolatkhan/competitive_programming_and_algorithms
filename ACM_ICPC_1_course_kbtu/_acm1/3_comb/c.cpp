#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("success.in", "r", stdin);
    freopen("success.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = -1, y = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            x = i;
            break;
        }
    }
    if (x == -1){
        for (int i = n - 1; i >= 0; i--) {
            cout << a[i] << " ";
        }
        return 0;
    }

    int temp = 1e9;
    for (int i = x + 1; i < n; i++) {
        if (a[x] < a[i]) {
            temp = min(temp, a[i]); 
        }
    }

    for (int i = x + 1; i < n; i++) {
        if (temp == a[i]) {
            y = i;
            break;
        }
    }

    swap(a[x], a[y]);
    
    reverse(a.begin() + x + 1, a.end());
    
    for (int i : a) cout << i << " "; cout << "\n";

    return 0;
}