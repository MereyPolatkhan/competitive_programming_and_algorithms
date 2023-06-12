#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string res = "";
    char cur = s[0];
    for (int i = 0; i < n; i++) {
        cur = s[i];
        i++;
        res += cur;
        while (s[i] != cur) {
            i++;
        }
    }

    cout << res << "\n";


}

int main() {    

    int l, r;
    cin >> l >> r;
    int m = (l + r) >> 1;
    cout << m;
    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
