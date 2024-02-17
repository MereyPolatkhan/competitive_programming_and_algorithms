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



bool win(int i1, int j1, int i2, int j2) {
    return i2 > i1 and (i2 - i1) % 2 and abs(j1 - j2) <= 1;
}

void solve() {
    int n, m, i1, j1, i2, j2;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;


    char who = 'a';
    while (true) {
        if (who == 'a') {  
            if (win(i1, j1, i2, j2)) {
                cout << "Alice\n";
                return;
            } 
            else if (i1 + 1 <= n) {
                bool first = false, second = false, third = false;
                if (!win(i1 + 1, j1, i2, j2)) {
                    first = true;
                }
                if (j1 - 1 >= 0 and !win(i1 + 1, j1 - 1, i2, j2)) {
                    second = true;
                }
                if (j1 + 1 <= m and !win(i1 + 1, j1 + 1, i2, j2)) {
                    third = true;
                }


                // if (first and second and third) {
                //     cout << "DRaw\n";
                //     return;
                // }
                if (first) {
                    i1++;
                }
                else if (second) {
                    i1++;
                    j1--;
                }
                else if (third) {
                    i1++;
                    j1++;
                }
                else  {
                    cout << "BOB\n";
                    return;
                }
            }
            else {
                cout << "Draw\n";
                return;
            }
            who = 'b';
        }
        else {
            if (win(i1, j1, i2, j2)) {
                cout << "BOB\n";
                return;
            }
            else if (i2 - 1 >= 0) {
                bool first = false, second = false, third = false;

                if (!win(i1, j1, i2 - 1, j2)) {
                    first = true;
                }
                if (j2 + 1 <= m and !win(i1, j1, i2 - 1, j2 + 1)) {
                    second = true;
                }
                if (j2 - 1 >= 0 and !win(i1, j1, i2 - 1, j2 - 1)) {
                    third = true;
                }

                // if (first and second and third) {
                //     cout << "DRAW\n";
                //     return;
                // }
                if (first) {
                    i2--;
                }
                else if (second) {
                    i2--;
                    j2++;
                }
                else if (third) {
                    i2--;
                    j2--;
                }
                else {
                    cout << "Alice\n";
                    return;
                }

            }

            else {
                cout << "Draw\n";
                return;
            }
            who = 'a';
        }   
    }
    
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
