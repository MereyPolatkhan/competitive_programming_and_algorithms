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
#define int long long 

typedef pair<int, int> pii;

vector<int> binary(int n) {
    vector<int> a;
    while (n) {
        a.pb(n % 2);
        n /= 2;
    }
    while (a.size() < 60) {
        a.pb(0);
    }
    return a;
}

void print(vector<int> &a) {
    for (int x: a) cout << x << ""; cout << "\n";
}

void solve() {
    int x, y, r;
    cin >> x >> y >> r; 

    vector<int> a = binary(x);
    vector<int> b = binary(y);
    vector<int> c = binary(r);

    int A = 0, B = 0, C = 0;
    for (int i = 0; i <= 59; i++) {
        bool temp = 0;
        if (A <= B) {
            temp = a[i];
        }
        else {
            temp = b[i];
        }
        temp = 1 - temp;
        if (C + pow(2, i) * temp <= r) {
            if (A <= B) {
                A += pow(2, i);
            }
            else {
                B += pow(2, i);
            }

            C += pow(2, i) * temp;
        }
        else {
            A += a[i] * pow(2, i);
            B += b[i] * pow(2, i);
        }
    }

    cout << abs(A - B) << "\n";
}
int32_t main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int T = 1;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        solve();
    }

    return 0;
}
