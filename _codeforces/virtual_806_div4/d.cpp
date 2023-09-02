#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


bool check(unordered_set<string> & st, string &s) {

    for (int i = 1; i < s.size(); i++) {
        if (st.count(s.substr(0, i)) and st.count(s.substr(i))) 
            return true;
    }


    return false;
}

void solve() {

    int n;
    cin >> n;

    vector<string> a(n);
    vector<int> res(n);
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (check(st, a[i]))    
            res[i] = 1;
        else    
            res[i] = 0;
    }

    for (int i : res) 
        cout << i;
    
    cout << "\n";

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
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

