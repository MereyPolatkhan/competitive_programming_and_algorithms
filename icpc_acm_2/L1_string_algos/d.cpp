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


vector<int> fast_odd(string s) {

    int n = s.size();

    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
    int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
    d1[i] = k;
    if (i+k-1 > r)
        l = i-k+1,  r = i+k-1;
    }   
    return d1;
}

vector<int> fast_even(string s) {
    int n = s.size();

    vector<int> d2 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
    int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
    while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
    d2[i] = k;
    if (i+k-1 > r)
        l = i-k,  r = i+k-1;
    }
    return d2;
}


void solve() {
    
    string s;
    cin >> s;

    vector<int> d1 = fast_odd(s), d2 = fast_even(s);
    ll cnt = 0;
    for (int i : d1) 
        if (i >= 2) 
            cnt += (i - 1);

    for(int i : d2)
        if (i >= 1) 
            cnt += i;


    // cout << "d1: "; for (int i : d1) cout << i << " "; cout << "\n";
    // cout << "d2: "; for (int i : d2) cout << i << " "; cout << "\n";

    cout << cnt << "\n";            
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
    #else
    freopen("palindrome.in", "r", stdin);
    freopen("palindrome.out", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

