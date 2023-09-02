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
















int n;

void calc(int i, vector<int> &a, vector<int> &cnt) {
    vector<int> temp;
    while (i != 0) {
        temp.pb(i);
        i = a[i];
        if (cnt[i] != -1 and cnt[i] != 0) {
            // cout << "here: ";
            // cout << i << " " << cnt[i] << "\n";
            temp.pb(i);
            temp.pb(cnt[i]);
            break;
        }
    }
    int fin = temp.back();

    for (int &x: temp) {
        if (x != fin) cnt[x] = fin;
        else cnt[x] = 0;
    }

}

void solve() {
    cin >> n;

    vector<int> a(n + 1, 0);

    vector<int> cnt(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == -1)
            calc(i, a, cnt);
    }


    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        // cout << i << ":" << cnt[i] << "\n";
        if (cnt[i] != 0) mp[cnt[i]]++;
    }
    if (mp.size() == 0) {
        cout << n << " " << 1 << "\n";
        return;   
    }

    int comp = 0;
    int mx = 0;

    for (auto &x: mp) {
        if (x.second > mx) {
            mx = x.second;
            comp = x.first;
        }
    }


    cout << comp << " " << mx + 1 << "\n";
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
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

