#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, m;

bool check(int day, map<int, int> mp) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &x: mp) {
            if (x.second >= day) {
                x.second -= day;
                // cout << "x.second : " << x.second << "\n";
                cnt++;
                break;
            }
        }
    }

    // cout << "\n\n";
    // cout << "day: " << day << "\n";

    // for (auto &x: mp) {
    //     cout << x.first << " : " << x.second << "\n";
    // }

    // cout << "\n\n";

    return cnt >= n;
}

void solve() {
    

    cin >> n >> m;

    map<int, int> mp;
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }


    for (int day = 1; day <= 1000; day++) {
        if (check(day, mp) == false) {
            cout << day - 1 << "\n";
            return;
        }
    }

}


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/







int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}

