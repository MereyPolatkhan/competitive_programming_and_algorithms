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



ull binpow(ull a, ull n, ull mod) {
    if (n == 0) {
        return 1LL * 1;
    }
    else if (n % 2 == 0) {
        ull bp = binpow(a, n / 2, mod);
        return bp * bp % mod;
    }
    else {
        return binpow(a, n - 1, mod) * a % mod;
    }
}



void Exponentiation() {
    ull a, b, c;
    cin >> a >> b >> c;

    const int mod = 1e9 + 7;


    cout << binpow(a, binpow(b, c, mod-1), mod) << "\n";
    
}

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        Exponentiation();
    }

    return 0;
}

