#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n\n";
}

void make_pref(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        a[i] += a[i - 1];
    }
}

void make_suf(vector<int>& a) {
    for (int i = a.size() - 2; i >= 0; i--) {
        a[i] += a[i + 1];
    }
}

int calculate_XOR(int n) {
  if (n % 4 == 0) return n; 
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1; 
  return 0;
}


ll power(ll x, ll y) {
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    for (int p = 1; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
  



void solve() {

    



    int n;
    cin >> n;

    int res = n / 3;
    int remainder = n % 3;

    if (remainder == 0) {
        cout << res << " " << res << "\n";
    }
    else if (remainder == 1) {
        cout << res + 1 << " " << res << "\n";
    }
    else {
        cout << res << " " << res + 1 << "\n";
    }









}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
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
