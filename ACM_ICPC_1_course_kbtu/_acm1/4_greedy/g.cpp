#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int>>> intervals;
unordered_map<int, pair<int, int>> mp;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.second == b.second.second) {
        return a.second.first > b.second.first;
    }
    return a.second.second < b.second.second;
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (mp.count(a[i])) {
            mp[a[i]].second = i;
        }
        else {
            mp[a[i]] = {i, i};
        }
    }

    for (auto i : mp) {
        intervals.push_back({i.first, {i.second.first, i.second.second}});           
    }

    sort(intervals.begin(), intervals.end(), cmp);


    // for (auto i : intervals) {
    //     cout << i.first << " - " << i.second.first << " " << i.second.second << "\n";           
    // }
    
    int cnt = 1;
    int finish = intervals[0].second.second;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].second.first > finish) {
            cnt++;
            finish = intervals[i].second.second;
        }
    }

    cout << intervals.size() - cnt;




    return 0;
}