#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

void fill_fac(vector<ull> & fac, ull n) {
    fac[0] = 1;
    ull factorial = 1;
    for (ull i = 1; i <= n; i++) {
        factorial *= i;
        fac[i] = factorial;
    }
}

void fill_digits(vector<ull> & digits, ull n) {
    for (ull i = 0; i < digits.size(); i++) {
        digits[i] = i + 1;
    }
}

void func(vector<ull> & res, vector<ull> & digits, vector<ull> & fac, ull n, ull k) {
    if (n == 1) {
        res.push_back(digits[0]);
    
        return;
    }
    ull index = k / (fac[n - 1]);
    if (k % (fac[n - 1]) == 0) {
        index--;
    }
    res.push_back(digits[index]);
    digits.erase(digits.begin() + index);
    k -= (fac[n - 1] * index);
    n--;
    func(res, digits, fac, n, k);
}

vector<ull> get_perm(ull n, ull k) {
    vector<ull> res;
    vector<ull> digits(n);
    vector<ull> fac(n + 1);
    fill_fac(fac, n);
    fill_digits(digits, n);
    func(res, digits, fac, n, k);



    return res;
}


void solve() {
    string s;
    cin >> s;
    ull kth;
    cin >> kth;
    
    ull n = s.size();

    unordered_map<ull, char> mp;

    for (ull i = 0; i < n; i++) {
        mp[i + 1] = s[i];
    }

    vector<ull> perm = get_perm(n, kth + 1);

    string res = "";

    for (ull i : perm) res += mp[i];

    cout << res << "\n";

}

int main() {

    ull t;
    cin >> t;
    while (t--){
        solve();
    }
  
    return 0;
}