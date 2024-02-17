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



void fast_odd() {
    string s;
    cin >> s;

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

    for (int i : d1) {
        cout << i << " ";
    }
    cout << "\n";
}

void fast_even() {
    string s;
    cin >> s;
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
    for (int i : d2) {
        cout << i << " ";
    }
    cout << "\n";
}


void slow() {   
    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1 (n),  d2 (n);
    for (int i=0; i<n; ++i) {
        d1[i] = 1;
        while (i-d1[i] >= 0 && i+d1[i] < n && s[i-d1[i]] == s[i+d1[i]])
            ++d1[i];
    
        d2[i] = 0;
        while (i-d2[i]-1 >= 0 && i+d2[i] < n && s[i-d2[i]-1] == s[i+d2[i]])
            ++d2[i];
    }
    for (int i = 0; i < n; i++) {
        cout << d1[i] << " ";
    }   
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << d2[i] << " ";
    }   
    cout << "\n";
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    fast_odd();
    cout << "\n";
    fast_even();
    return 0;
}



