#include <bits/stdc++.h>


using namespace std;


int main() {

    long long n, k;
    cin >> n >> k;
    
    vector<long long> a(n + 1, 0);

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long i = 1;
    long long j = n;
    long long res = 0;
    while (i <= j) {
        if (a[i] + a[j] <= k) {
            i++;
            j--;
        }
        else {
            if (a[i] > k || a[j] > k) {
                cout << "Impossible\n";
                return 0;
            }
            j--;
        }
        res += 1;
    }

    cout << res;


    return 0;
}