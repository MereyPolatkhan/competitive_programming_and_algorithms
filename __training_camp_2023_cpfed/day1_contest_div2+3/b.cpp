#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, k, x;


int func(vector<int> a, int i, int j) {
    i--;
    while (i >= 0 and j < n) {
        int cnt = 0;
        int c = a[i];
        while (i >= 0 and c == a[i]) {
            i--;
            cnt++;
        }
        while (j < n and c == a[j]) {
            j++;
            cnt++;
        }

        if (cnt <= 2) {
            return 3;
        }
        else {
            
        }

    }
}

void solve() {  
    cin >> n >> k >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;

    int i = 0;
    while (i < n) {
        if (a[i] != x) {
            i++;
        }
        else {
            int j = i;
            int cnt = 0;
            while (j < n and a[j] == x) {
                j++;
                cnt++;
            }

            if (cnt == 2) {
                res = max(res, func(a, i, j));
            }
        }
    }

    cout << res << "\n";
    
}



int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

