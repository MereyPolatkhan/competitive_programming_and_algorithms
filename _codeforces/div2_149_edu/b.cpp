#include <bits/stdc++.h>


using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;


    vector<int> a;
    a.push_back(1000);

    int minn = a[0];
    int maxx = a[0];
    int i = 0; 
    while (i < n) {
        int last = a.back();
        if (s[i] == '<') {

            int cnt = 0;
            int j = i;
            while (j < n and s[j] == '<') {
                cnt++;
                j++;
            }
            int from = -1e9;
            if ((maxx - cnt + 1) <= last) {
                from = minn + 1;
            }
            else {
                from = maxx - cnt + 1;
            }

            while (s[i] == '<') {
                a.push_back(from); from++;
                i++;
                minn = min(minn, a.back());
                maxx = max(maxx, a.back());
            }
            i--;
        }
        else if (s[i] == '>') {

            int cnt = 0;
            int j = i;
            while (j < n and s[j] == '>') {
                cnt++;
                j++;
            }
            int from = -1e9;
            if ((minn + cnt - 1) >= last) {
                from = maxx - 1;
            }   
            else {
                from = minn + cnt - 1;
            }
            while (s[i] == '>') {
                a.push_back(from); from--;
                i++;
                minn = min(minn, a.back());
                maxx = max(maxx, a.back());
            }
            i--;
        }
        i++;
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < a.size(); i++) {
        mp[a[i]]++;
    }
    cout << mp.size() << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}