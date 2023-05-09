#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;

    int short_res = INT_MAX;

    for (int r = 0; r < n; r++) {
        add(a[r]);
        while (!good()) {
            remove();
            l++;
        }
        short_res = min(short_res, r - l + 1);
    }

    cout << short_res;




    return 0;
}