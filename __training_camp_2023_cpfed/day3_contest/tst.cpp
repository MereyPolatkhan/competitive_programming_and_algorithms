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


















void solveA() {


    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            cnt++;
        }
    }

    cout << (cnt + 1) / 2 << "\n";
}

void solveB() {
    ll n;
    cin >> n;



}

int n;
int mx, mn;


vector<pii> all_positive(vector<int> a) {
    vector<pii> res;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            j = i;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= a[i + 1]) {
            continue;
        }
        else {
            if (a[i + 1] == mx) {
                while (a[i] > a[i + 1]) {
                    a[i + 1] += mx;
                    res.pb({i + 1, j});
                }
                mx = a[i + 1];
            }
            else {
                while (a[i] > a[i + 1]) {
                    a[i + 1] += mx;
                    res.pb({i + 1, j});
                }
            }
        }
    }

    return res;
}

vector<pii> all_neg(vector<int> a) {
    vector<pii> res;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mn) {
            j = i;
            break;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        if (a[i - 1] <= a[i]) {
            continue;
        }
        else {
            if (a[i - 1] == mn) {
                while (a[i - 1] > a[i]) {
                    a[i - 1] += mn;
                    res.pb({i - 1, j});
                }
                mn = a[i - 1];
            }
            else {
                while (a[i - 1] > a[i]) {
                    a[i - 1] += mn;
                    res.pb({i - 1, j});
                }
            }
        }
    }

    return res;
}


void go(vector<pii> &res) {
    cout << "sz: " << res.size() << "\n";
    for (auto &i : res) cout << i.first + 1 << " " << i.second + 1 << "\n";
    cout << "\n\n";
}

vector<pii> make_min(vector<int> a) {
    vector<pii> res;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (mn == a[i]) {
            j = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            while (a[i] > 0) {
                a[i] -= mn;
                res.pb({i, j});
            }
        }
    }

    cout 

    for (int i = n - 1; i >= 1; i--) {
        if (a[i - 1] <= a[i]) {
            continue;
        }
        else {
            if (a[i - 1] == mn) {
                while (a[i - 1] > a[i]) {
                    a[i - 1] += mn;
                    res.pb({i - 1, j});
                }
                mn = a[i - 1];
            }
            else {
                while (a[i - 1] > a[i]) {
                    a[i - 1] += mn;
                    res.pb({i - 1, j});
                }
            }
        }
    }

    return res;



}

vector<pii> make_max(vector<int> a) {
    vector<pii> res;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            j = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            while (a[i] < 0) {
                a[i] += mx;
                res.pb({i, j});
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= a[i + 1]) {
            continue;
        }
        else {
            if (a[i + 1] == mx) {
                while (a[i] > a[i + 1]) {
                    a[i + 1] += mx;
                    res.pb({i + 1, j});
                }
                mx = a[i + 1];
            }
            else {
                while (a[i] > a[i + 1]) {
                    a[i + 1] += mx;
                    res.pb({i + 1, j});
                }
            }
        }
    }

    return res;



}

void solve() {
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mx = *max_element(all(a)), mn = *min_element(all(a));

    if (mx == mn) {
        cout << "sz: " << 0 << "\n";
        return;
    }

    if (mx > 0 and mn > 0) {
        vector<pii> res = all_positive(a);
        go(res);
    }
    else if (mx < 0 and mn < 0) {
        vector<pii> res = all_neg(a);
        go(res);
    }
    else {
        if (abs(mn) > abs(mx)) {
            vector<pii> res = make_min(a);
            go(res);
        }
        else {
            vector<pii> res = make_max(a);
            go(res);
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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

