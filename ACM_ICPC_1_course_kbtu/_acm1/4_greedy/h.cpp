#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int, pair <int, int> > a, pair <int, pair <int, int> > b) {
    int s1 = a.second.first * b.second.second;
    int s2 = b.second.first * a.second.second;

    if (s1 == s2) {
        return a.first < b.first;
    }
    
    return (s1 < s2);
}

int main() {
    int n;
    while (cin >> n) {

        vector< pair <int, pair <int, int> > > a;

        for (int i = 0; i < n; i++) {
            int kun, penalty;
            cin >> kun >> penalty;

            a.push_back({i + 1, {kun, penalty}});
        }

        sort(a.begin(), a.end(), cmp);

        for (auto i: a) {
            cout << i.first << " ";
        }
        cout << "\n";
    }
    return 0;
}