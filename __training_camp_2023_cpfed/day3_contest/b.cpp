#include <bits/stdc++.h>

using namespace std;


bool cmp(pair< pair<long long, long long>, long long > a, pair< pair<long long, long long>, long long > b) {
    // if (a.first.second == b.first.second) {
    //     return a.first.first > b.first.first;
    // }
    return a.first.second < b.first.second;
}

int main() {

    long long s, n;
    cin >> s >> n;

    vector< pair< pair<long long, long long>, long long > > a;

    for (long long i = 1; i <= n; i++) {
        long long x, y;
        cin >> x >> y;
        a.push_back({{x, y}, i});
    }

    sort(a.begin(), a.end(), cmp);


    long long sum = 0;
    vector<long long> res;
    priority_queue<pair<long long, long long>> pq;
    long long i = 0;
    while (sum < s) {
        while (i < n and a[i].first.second <= sum) {
            pq.push({a[i].first.first, a[i].second});
            i++;
        }
        if (pq.size() == 0) {
            break;
        }
        sum += pq.top().first;
        res.push_back(pq.top().second);
        pq.pop();
    }


    if (sum >= s and res.size() >= 1) {
        cout << res.size() << "\n";
        for (long long i : res) cout << i << " ";
    }
    else cout << "-1\n";

    return 0;
}