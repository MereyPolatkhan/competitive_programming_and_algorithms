#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;
    cin >> n;
    
    map<int, int> m;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                m[i] = cnt;
                n /= i;
            }
        }
    }

    if (n > 1) m[n] = 1;



    int it = 1;
    int sz = m.size();

    for (auto i: m) {
        if (i.second > 1) cout << i.first << "^" << i.second;
        else cout << i.first;
        
        if (it != sz) {
            cout << "*";
        }
        it++;
    }



    return 0;
}