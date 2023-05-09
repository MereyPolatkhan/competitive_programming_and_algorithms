#include <bits/stdc++.h>

using namespace std;

int func(int n, int k){
    int res = (k-1)/(n-1) + k;
    return res;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cout << func(n, k) << "\n";
    }


    return 0;
}