#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> ch;
    vector<int> ne;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) ch.push_back(i + 1);
        else ne.push_back(i + 1);
    }

    if (ne.size() >= 3) {
        cout << "YES\n";
        for (int i = 0; i < 3; i++) cout << ne[i] << " ";
        cout << "\n";
    }
    
    else if (ne.size() >= 1 and ch.size() >= 2)  {
        cout << "YES\n";
        cout << ne[0] << " ";
        for (int i = 0; i < 2; i++) cout << ch[i] << " ";
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }

}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}