#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
    return a.first > b.first;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<pair<int, vector<int>>> a;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            sum += x;
            temp.push_back(x);
        }

        a.push_back({sum, temp});
    }


    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i].first << ": ";
        for (int j = 0; j < a[i].second.size(); j++) {
            cout << a[i].second[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}