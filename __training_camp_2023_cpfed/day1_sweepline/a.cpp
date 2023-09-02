#include <bits/stdc++.h>

using namespace std;



int main() {

    int n, m;
    cin >> n >> m;

    multiset<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) 
            swap(x, y);
        st.insert({x, 1});
        st.insert({y, 3});
    }

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.insert({x, 2});
        b[i] = x;
    }

    int cnt = 0;

    map<int, int> mp;

    for (const pair<int, int> &x: st) {
        if (x.second == 1) {
            cnt++;
        }
        else if (x.second == 3) {
            cnt--;
        }
        else {
            mp[x.first] = cnt;
        }
    }


    for (int &x: b) {
        cout << mp[x] << " ";
    }

    return 0;
}