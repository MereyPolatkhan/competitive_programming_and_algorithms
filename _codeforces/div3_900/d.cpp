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

int n, k;
string s;

pii binpoisk(int x, vector<int> l, vector<int> r) {
    int left = -1, right = k; // [0, k - 1];
    while (left < right - 1) {
        int mid = (left + right) / 2;
        if (l[mid] <= x and x <= r[mid]) {
            return {l[mid], r[mid]};
        }
        else if (x < l[mid]) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    return {l[left], r[left]};
}

pii lin(int x, vector<int> l, vector<int> r) {
    pii res;
    for (int i = 0; i < k; i++) {
        if (l[i] <= x and x <= r[i]) {
            res.first = l[i];
            res.second = r[i];
        }
    }
    return res;
}



void solve() {
    cin >> n >> k;

    cin >> s;

    vector<int> l(k);
    for (int i = 0; i < k; i++) 
        cin >> l[i];

    vector<int> r(k);
    for (int i = 0; i < k; i++) 
        cin >> r[i];

    int q;
    cin >> q;

    vector<pii> revs;


    for (int j = 0; j < q; j++) {
        int x;
        cin >> x;

        pii lr = binpoisk(x, l, r);
        int l = lr.first;
        int r = lr.second;


        int a = min(x, l + r - x);
        int b = max(x, l + r - x);
        a--;
        b--;

        // reverse(s.begin() + a, s.begin() + b + 1);

        revs.pb({a, b});
    }


    int i = 0;
    while (i < revs.size()) {
        int j = i + 1;
        int cnt = 1;
        while (j < revs.size() and revs[i] == revs[j]) {
            cnt++;
            j++;
        }


        if (cnt % 2) {
            reverse(
                s.begin() + revs[i].first,
                s.begin() + revs[i].second + 1);
        }
        i = j;
    }

    cout << s << "\n";

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
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

