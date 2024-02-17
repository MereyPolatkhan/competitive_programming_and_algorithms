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
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef unsigned short int usi;


vector<int> factorization(int n) {
    vector<int> res;
    for (int i = 2; i * i <= (n); i++) {
        while (n % i == 0) {
            res.pb(i);
            n /= i;
        }
    }
    if (n > 1) res.pb(n);

    return res;
} 

void solve() {
    int n;
    cin >> n;

    int cnt = 0;

    while (n > 1) {
        if (n % 2 == 1) {
            n /= n;
        }
        else {
            vector<int> f = factorization(n);
            int cntOdd = 0, cntEven = 0;
            for (int &x: f) {
                if (x % 2) 
                    cntOdd++;
                else        
                    cntEven++;
            }
            if (cntOdd == 0) {
                n--;
            }
            else {
                int d = 1;
                if (cntEven == 1) {
                    for (int &x: f) {
                        if (x % 2 and cntOdd >= 2) {
                            d *= x;
                            cntOdd--;
                        }   
                    }
                }
                else {
                    for (int &x: f) 
                        if (x % 2)  
                            d *= x;
                }
                
                n /= d;
                if (d == 1)
                    n--;
            }
        }
        // cout << n << "\n";
        cnt++;
    }


    if (cnt % 2) 
        cout << "Ashishgup\n";
    else 
        cout << "FastestFinger\n";
}


/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cout << "\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        // cout << "test: #" << test << "\n";
        solve();
    }

    return 0;
}