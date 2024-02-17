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


void solve() {
    int n;
    cin >> n;


    vector<int> a(n);
    priority_queue<int> odd, even;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            odd.push(a[i]);
        }
        else {
            even.push(a[i]);
        }
    }


    ll alice = 0, bob = 0;
    int turn = 0;
    while (turn < n) {
        if (turn % 2 == 0) {
            if (!even.size() and odd.size()) {
                odd.pop();
            }
            else if (even.size() and odd.size() and odd.top() > even.top()) {
                odd.pop();
            }
            else if (even.size()) {
                int top = even.top();
                even.pop();
                alice += top;
            }
        }
        else {  
            if (!odd.size() and even.size()) {
                even.pop();
            }
            else if (even.size() and odd.size() and even.top() > odd.top()) {
                even.pop();
            }          
            else if (odd.size()) {
                int top = odd.top();
                odd.pop();
                bob += top;
            }
        }
        // cout << "turn: " << turn << " alice: " << alice << " bob: " << bob << "\n";
        turn++;
    }   

    if (alice > bob) {
        cout << "Alice\n";
    }
    else if (alice < bob) {
        cout << "Bob\n";
    }
    else {
        cout << "Tie\n";
    }
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

