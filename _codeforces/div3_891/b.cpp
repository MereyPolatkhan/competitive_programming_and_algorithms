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

vector<int> SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<int> res;
    for (int p = 1; p <= n; p++) {
        if (prime[p]) {
            // cout << p << " ";
            res.pb(p);
        }
    }
    return res;
}
  


vector<int> factorization(int n) {
    vector<int> res;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            // cout << i << " ";
            res.pb(i);
            n = n / i;
        }
    }
    // if (n > 1) cout << n << " ";
    if (n > 1) res.pb(n);

    return res;
} 


vector<ll> divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i <= sqrt(n); i++){
        if (n % i == 0) {
            if (n / i == i){
                // cout <<" "<< i;
                res.pb(i);
            }
            else {
                // cout << " "<< i << " " << n/i;
                res.pb(i);
                res.pb(n / i);
            } 
        }
    }
    sort(all(res));
    return res;
}



bool is_n_pow_of_2(int n) {
    if (n == 0) return false;
    return ((n - 1) & n) == 0;
}

// Safa genii: "тупо решать много задач и запомнить паттерны/approach"






















int ctoi(char c) {
    return (int)c - (int)'0';
}

char itoc(int n) {
    return (char)(n + (int)'0');
}

void solve() {
    string s;
    cin >> s;


    reverse(all(s));
    s += '0';
    reverse(all(s));

    int n = s.size();

    int last_0 = n - 1;

    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '9') {
            int j = i;
            while (s[j] == '9') {
                j--;
            }
            s[j] = itoc(ctoi(s[j]) + 1);
            int temp = j;
            j++;
            while (j <= last_0) {
                s[j] = '0';
                j++;
            }
            last_0 = temp;
        }
        else if (ctoi(s[i]) >= 5) {
            if (ctoi(s[i - 1]) == 9) {
                int j = i - 1;
                while (s[j] == '9') {
                    j--;
                }
                s[j] = itoc(ctoi(s[j]) + 1);
                int temp = j;
                j++;
                while (j <= last_0) {
                    s[j] = '0';
                    j++;
                }
                last_0 = temp;
            }   
            else {
                s[i - 1] = itoc(ctoi(s[i - 1]) + 1);
                int j = i;
                while (j <= last_0) {
                    s[j] = '0';
                    j++;
                }
                last_0 = i;
            }
        }
    }
    if (s[0] == '0') {
        cout << s.substr(1) << "\n";
    }
    else {
        cout << s << "\n";
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

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

