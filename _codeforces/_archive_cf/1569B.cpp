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

    char a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) a[i][j] = 'X';
            else a[i][j] = '0';
        }
    } 

    vector<bool> satisfied(n, false);

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (a[i][j] == '0') {
                    a[i][j] = '=';
                    a[j][i] = '=';
                }
            }
            satisfied[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (a[i][j] == '0') {
                    if (a[j][i] == '+') {
                        a[i][j] = '-';                        
                    }
                    else if (a[j][i] == '0') {
                        a[i][j] = '+';
                        a[j][i] = '-';
                        break;
                    }
                    // never happens below
                    else if (a[j][i] == '-') {
                        a[i][j] = '+';
                    }
                    else if (a[j][i] == '=') {
                        a[i][j] = '=';
                        continue;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {   
        if (s[i] == '2') {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '0') {
                    if (a[j][i] == '+') {
                        a[i][j] = '-';                        
                    }
                    else if (a[j][i] == '-') {
                        a[i][j] = '+';
                    }
                    else if (a[j][i] == '=' || a[j][i] == '0') {
                        a[i][j] = '=';
                        a[j][i] = '=';
                    }
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '+') {
                    satisfied[i] = true;
                    break;
                }
            }            
        }
    }
    for (auto x : satisfied) {
        if (x == false) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
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
