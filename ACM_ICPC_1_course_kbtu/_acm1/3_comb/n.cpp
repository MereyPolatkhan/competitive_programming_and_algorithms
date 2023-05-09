#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


void func(ull fac, ull n, ull k, vector<ull> & a, vector<bool> & used) {
    if (n == 1) {

        for (int i = 1; i <= used.size() - 1; i++) {
            if (used[i] == false) {
                a.push_back(i);
                break;
            }
        }   

        return;
    }

    ull block_size = fac / n;
    ull number = ceil((k * (1.0)) / (block_size * (1.0)));
 
    // cout << "num: " << number << " k: " << k << " blsz: " << block_size << "\n";
 
    used[number] = true;
    a.push_back(number);
    
    k = k % block_size;

    if (k == 0) {
        for (int i = used.size() - 1; i >= 1; i--){ 
            if (used[i] == false) {
                a.push_back(i);
            }
        }
        return;
    }

    fac = fac / n;
    n = n - 1;
    func(fac, n, k, a, used);
}

void solve() {
    string s; ull k;
    cin >> s >> k;
    
    sort(s.begin(), s.end());
    k++;


    unordered_map<ull, char> mp;
    ull n = s.size();
    for (ull i = 0; i < n; i++) {
        mp[i + 1] = s[i];
    }

    ull fac = 1;
    for (ull i = 1; i <= n; i++) {
        fac *= i;
    }

    vector<ull> a;
    vector<bool> used(n + 1, false);
    func(fac, n, k, a, used);

    string res = "";
    for (auto i : a) {
        res += mp[i];
    }
    cout << res << "\n"; 
}


int main() {

    int t;
    cin >> t;
    while (t--){
        solve();
    }
 
    return 0;
}