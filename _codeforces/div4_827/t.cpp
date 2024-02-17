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
    set<char> s;
    set<char> t;
    for (int i = 0; i < 3; i++)  {
        char c;
        cin >> c;
        s.insert(c);
    }    
    for (int i = 0; i < 3; i++)  {
        char c;
        cin >> c;
        t.insert(c);
    }   

    if (s < t) {
        cout << "s < t";
    } 
    else if (s > t) {
        cout << "s > t";
    }
    else {
        cout << "equal";
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
    solve();

    return 0;
}

