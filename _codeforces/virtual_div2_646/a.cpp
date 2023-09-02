#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef pair<int, int> pii;

#define ll long long
#define ull unsigned long long
#define pb push_back

 
void solve() {
    int n, x;
    cin >> n >> x;

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x % 2 == 0) even++;
        else odd++;
    }
    if (odd == 0) {
        cout << "NO\n";
        return;
    }
    if (odd > x) {
        if (x % 2 == 1) {
            cout << "YES\n";
        }
        else {
            if (even >= 1) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    else if (odd < x) {
        if (odd % 2 == 0) {
            odd--;
        }
        x -= odd;
        if (even >= x) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        if (odd % 2 == 0) {
            if (even >= 1) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
        }
    }


}
 
 
int main() {
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
 
    return 0;
}