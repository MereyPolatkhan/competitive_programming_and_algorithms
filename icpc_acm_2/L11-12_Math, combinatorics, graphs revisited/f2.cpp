#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <climits>
#include <stack>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;

ll const MOD = (ll)1e9 + 7;
int const N = (int)1e5;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return ((res * res) % MOD * a) % MOD;
    else
        return res * res % MOD;
}



void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<ll> cnt(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            cnt[i] += mp[j];
        }   
    }

    vector<ll> res(N + 1, 0);
    for (int i = N; i >= 1; i--) {
        ll temp = binpow(2, cnt[i]) - 1;
        for (int j = i; j <= N; j += i) {
            temp -= res[j];
            temp = (temp + MOD) % MOD;
        }
        res[i] = temp;
    }
    cout << res[1] << "\n";
}   



int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}

