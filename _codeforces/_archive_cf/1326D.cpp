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


vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

string func(string &t) {
    string revt = t;
    reverse(all(revt));
    string s = t + '$' + revt;
    // cout << "s: " << s << "\n";
    vector<int> p = prefix_function(s);

    int len = p.back();

    return s.substr(0, len);
}

string get_palindrome(string &s, int left, int right) {
    string t = s.substr(left, right - left + 1);
    string pref = func(t);
    reverse(all(t));
    string suff = func(t);
    if (pref.size() > suff.size())
        return pref;
    return suff;
}


void solve() {
    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] == s[r])
            l++, r--;
        else {
            break;
        }
    }

    string res = "";
    if (l >= r) 
        res = s;
    else {
        res += s.substr(0, l);
        res += get_palindrome(s, l, r);
        res += s.substr(r + 1);
    }
    cout << res << "\n\n\n";
    
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
