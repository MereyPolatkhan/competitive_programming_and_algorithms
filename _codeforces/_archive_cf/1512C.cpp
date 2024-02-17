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
    int zeros, ones;
    cin >> zeros >> ones;

    string s;
    cin >> s;

    int n = s.size(); 

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') 
            ones--;
        else if (s[i] == '0') 
            zeros--;
    }



    for (int i = 0; i < (n + 1)/ 2; i++) {
        int j = n - 1 - i;
        if (s[i] == s[j]) {
            if (i == j) {
                if (ones % 2) 
                    s[i] = '1', ones--;
                else if (zeros % 2)    
                    s[i] = '0', zeros--;
                break;
            }
            else 
                continue;
        }

        if (s[i] != '?' and s[j] != '?') {
            cout << -1 << "\n";
            return;
        }
        
        if (s[i] == '?') {
            s[i] = s[j];
        }
        else if (s[j] == '?') {
            s[j] = s[i];
        }

        if (s[i] == '1') {
            ones--;
        }
        else {
            zeros--;
        }
    }

    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if (s[i] == s[j] and s[i] == '?') {
            if (ones > zeros) {
                s[i] = '1';
                s[j] = '1';
                ones -= 2;
            }
            else {
                s[i] = '0';
                s[j] = '0';
                zeros -= 2;
            }
        }
    }   

    if (!zeros and !ones)    
        cout << s << "\n";
    else   
        cout << -1 << "\n";
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

