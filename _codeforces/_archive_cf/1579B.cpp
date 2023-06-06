#include <bits/stdc++.h>


using namespace std;

struct shift {
    int l;
    int r;
    int d;
};


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector< shift > res;

    for (int i = 1; i <= n; i++) {
        int index = i;
        int mn = a[i];
        for (int j = i; j <= n; j++) {
            if (a[j] < mn) {
                mn = a[j];
                index = j;
            }
        }
        shift r;
        r.l = i;
        r.r = index;
        r.d = index - i;
        if (r.d > 0)
            res.push_back(r);
       
        for (int j = index; j >= i + 1; j--) {
            a[j] = a[j - 1];
        }
        a[i] = mn;
    }


    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n\n\n";

    cout << res.size() << "\n";
    for (auto i: res) cout << i.l << " " << i.r << " " << i.d << "\n";

}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }    


    return 0;
}