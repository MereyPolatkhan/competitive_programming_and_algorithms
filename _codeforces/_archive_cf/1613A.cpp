#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;

int len(int x) {
    int cnt = 0;
    while (x > 0) {
        x /= 10;
        cnt++;
    }
    return cnt;
}

void make(int &a, int &b, int &p) {
    while (len(a) < len(b)) {
        a *= 10;
        p--;
    }
}

void solve() {

    int x1, p1;
    int x2, p2;
    int len1, len2;

    cin >> x1 >> p1;
    cin >> x2 >> p2;

    len1 = len(x1);
    len2 = len(x2);

    if (len1 + p1 < len2 + p2) {
        cout << "<\n";
    }
    else if (len1 + p1 > len2 + p2) {
        cout << ">\n";
    }
    else {
        make(x1, x2, p1);
        make(x2, x1, p2);
        if (x1 == x2 and p1 == p2) {
            cout << "=\n";
        }
        else if (x1 < x2) {
            cout << "<\n";    
        }
        else {
            cout << ">\n";    
        }
    }

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
