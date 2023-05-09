#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define r freopen("input.txt", "r", stdin)
#define w freopen("output.txt", "w", stdout)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)



int main() {
    fast;
    ull n;
    cin >> n;

    vector<int> a;

    while (n > 0) {
        a.push_back(n % 2);
        n = n / 2;
    }
    reverse(a.begin(), a.end());

    string s = "";

    bool flag = false;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            if (flag == false) flag = true;
            else {
                s += "SX";
            }
        }   
        else {
            s += "S";
        }
    }

    cout << s;
    return 0;
}