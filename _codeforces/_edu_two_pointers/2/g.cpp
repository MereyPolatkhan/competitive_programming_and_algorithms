#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = INT_MAX;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        while (good() == false) {
            l++;
        }
        if (good()) res = min(res, r - l + 1); 
    }
    


    return 0;
}