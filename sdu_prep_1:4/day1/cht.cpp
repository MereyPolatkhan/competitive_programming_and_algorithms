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



class cht {
private: 
    vector<pair<int, int>> a;
    bool check_to_delete(int k_C, int b_C) {
        int k_A = a[a.size() - 2].first, b_A = a[a.size() - 2].second;
        int k_B = a[a.size() - 1].first, b_B = a[a.size() - 1].second;
        return ((1LL * b_A - b_B) * (k_C - k_B) >= (1LL * k_B - k_A) * (b_B - b_C));
    }
    ll calc(int k, int x, int b) {
        return (long long)k * x + b;
    }

public:
    void push(int k, int b) {      
        if (a.size() <= 1) {
            a.pb({k, b});
        }
        else {
            while (a.size() >= 2 and check_to_delete(k, b)) {
                a.pop_back();
            }
            a.push_back({k, b});
        }        
    }


    ll get_MAX(int x) {
        if (a.size() <= 2) {
            ll res = LLONG_MIN;
            for (int i = 0; i < a.size(); i++) {
                res = max(res, calc(a[i].first, x, a[i].second));
            }
            return res;        
        }
        else {
            // binary search
            int l = 0;
            int r = a.size() - 1;

            while (l < r) {
                int mid = (l + r) / 2;
                if (calc(a[mid].first, x, a[mid].second) >= calc(a[mid + 1].first, x, a[mid + 1].second))
                    r = mid;
                else    
                    l = mid + 1;
            }
            return calc(a[l].first, x, a[l].second);
        }
    }   
};





int q;
int t;
int k, b;
int x;




void solve() {
    cin >> q;

    int cases;
    cin >> cases;   

    vector<pair<int, pii> > queries(q);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, b;
            cin >> k >> b;
            queries[i] = {type, {k, b}};
        }
        else if (type == 2) {
            int x;
            cin >> x;
            queries[i] = {type, {x, -1}};
        }
    }



    cht c;
    for (int i = 0; i < q; i++) {
        // 1 - mi > mi+1, and all queries are for minimum.
        if (cases == 1) {
            if (queries[i].first == 1) {
                c.push(-1 * queries[i].second.first, -1 * queries[i].second.second); // (-k, -b);
            }
            else if (queries[i].first == 2) {
                cout << -1 * c.get_MAX(queries[i].second.first) << "\n"; // - 1 * ans(x);
            }
        }
        
        // 2 - mi > mi+1, and all queries are for maximum.
        else if (cases == 2) {
            if (queries[i].first == 1) {
                c.push(-1 * queries[i].second.first, queries[i].second.second); // (-k, b);
            }
            else if (queries[i].first == 2) {
                cout << c.get_MAX(-1 * queries[i].second.first) << "\n"; // ans(-x);
            }
        }
        
        // 3 - mi < mi+1, and all queries are for minimum.
        else if (cases == 3) {
            if (queries[i].first == 1) {
                c.push(queries[i].second.first, -1 * queries[i].second.second); // (k, -b);
            }
            else if (queries[i].first == 2) {
                cout << -1 * c.get_MAX(-1 * queries[i].second.first) << "\n"; // -1 * ans(-x);
            }
        }

        // 4 - mi < mi+1, and all queries are for maximum.
        else if (cases == 4) {
            if (queries[i].first == 1) {
                c.push(queries[i].second.first, queries[i].second.second); // (k, b)
            }
            else if (queries[i].first == 2) {
                cout << c.get_MAX(queries[i].second.first) << "\n"; // ans(x)
            }
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

