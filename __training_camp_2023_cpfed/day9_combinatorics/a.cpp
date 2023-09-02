#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
#define int long long
#define ll long long

const ll mod = 1000000007;

int N = (int)1e6 + 7; 
 
vector<int> fact(N), inv(N);

int binpow(int x, unsigned int y, int p){
    int res=1; x=x%p;
    while(y>0){
        if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
    }
    return res;
} 
 
 
void precalc() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binpow(fact[i], mod - 2, mod) % mod;
    }
}
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
 
    // for (int i = 0; i <= n; i++) {
    //     cout << "i : " << i << "  fact[i]: " << fact[i] << " inv[i]: " << inv[i] << "\n";
    // }
 
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
 

    int a[26] = {0};
    for (auto i: s)     
        a[i - 'a']++;
    int ans = fact[n];
    for (int i = 0; i < 26; i++) {
        ans = ans * inv[a[i]] % mod;
    }

    cout << ans << "\n";
}   
 
 
 
/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
 
 
 
signed main() {   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    precalc();
 
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}
