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



unsigned long long fact[15];
unsigned long long bad[5];

void perm(vector<unsigned long long> &a, vector<unsigned long long> & temp, unsigned long long &cnt) {
    if (a.size() == temp.size()) {
        bool flag = true;
        for (unsigned long long i = 0; i < temp.size(); i++) {
            if (temp[i] == i + 1) {
                flag = false;
            }
        }
        if (flag)
            cnt++;
    }
    else {
        for (unsigned long long x: a) {
            if (find(temp.begin(), temp.end(), x) != temp.end()) {
                continue;
            }
            else {
                temp.push_back(x);
                perm(a, temp, cnt);
                temp.pop_back();
            }
        }
    }
}

unsigned long long do_bads(unsigned long long n) {
    vector<unsigned long long> a(n);
    for (unsigned long long i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    vector<unsigned long long> temp;
    unsigned long long cnt = 0;
    perm(a, temp, cnt);
    return cnt;
}

void precalc() {
    fact[0] = 1;

    for (unsigned long long i = 1; i <= 5; i++) {
        fact[i] = (fact[i - 1] * i);
    }

    for (unsigned long long i = 0; i <= 4; i++) {
        bad[i] = do_bads(i);
    }
}

unsigned long long comb(int n, int k) {
    unsigned long long res = 1;
    for (unsigned long long i = n - k + 1; i <= n; i++) {
        res *= i;
    }
    return res / fact[k];
}


void solve() {


    unsigned long long n, k;
    cin >> n >> k;

    unsigned long long res = 0;

    for (unsigned long long i = 0; i <= k; i++) {
        res += (comb(n, i) * bad[i]);
    }
    cout << res << "\n";
}

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    precalc();

    unsigned long long T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

