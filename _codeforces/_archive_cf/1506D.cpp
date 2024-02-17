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


void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }


    multiset<int> st;
    for (auto it: mp) {
        // cout << it.first << ": " << it.second << "\n";
        st.insert(it.second);
    }


    while (st.size() >= 2) {
        int a = *st.rbegin(); st.erase(st.find(*st.rbegin()));
        int b = *st.rbegin(); st.erase(st.find(*st.rbegin()));
        
        a--; 
        b--;

        if (a) st.insert(a);
        if (b) st.insert(b);
    }

    if (st.size()) 
        cout << *st.begin() << "\n";
    else    
        cout << 0 << "\n";
    
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
