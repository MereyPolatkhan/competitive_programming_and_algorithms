#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n, s;
    cin >> n >> s;

    ll a[n];


    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int res = 0;
    ll sum = 0;
    
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > s) {
            sum -= a[l];
            l++;
        }

        res = max(res, r - l + 1);
    }

    cout << res;
    return 0;
}