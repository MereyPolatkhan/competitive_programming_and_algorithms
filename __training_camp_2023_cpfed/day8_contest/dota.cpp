#include <bits/stdc++.h>


using namespace std;



bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}


int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), cmp);


    long long sum_bi = 0;
    for (int i = 0; i < n; i++) {

    }



    return 0;
}