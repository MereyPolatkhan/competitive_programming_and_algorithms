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
#include <stack>


using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


int it = 0;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    
    int odd = 0, even = 0;

    for (auto &it: mp) {
        odd += it.second % 2;
        even += it.second / 2;
    }

    int res = even / k * 2;
    if (odd + (even % k)* 2 >= k) 
        res++;

    cout << res << "\n";

}

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }


    return 0;
}
