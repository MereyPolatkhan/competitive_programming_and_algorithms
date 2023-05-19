#include <bits/stdc++.h>


using namespace std;

void solve() {
    int n, capsules, vaccine_time, patient_time;
    cin >> n >> capsules >> vaccine_time >> patient_time;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int time = patient_time + vaccine_time;
    int mx = a[n];
    int cnt = 0;
    int res = 0;
    for (int i = n; i >= 1; i--) {
        if (time >= mx - a[i]) {
            cnt++;
        }
        if (time < mx - a[i] || cnt > capsules) {
            res++;
            cnt = 1;
            mx = a[i];
        }
    }

    res++;

    cout << res << "\n";


    
}

int main() {


    int t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}