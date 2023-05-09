#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll> a;

ll parent(ll i){
    return (i - 1) / 2;
}

ll left(ll i) {
    return 2 * i + 1;
}

ll right(ll i) {
    return 2 * i + 2;
}


void sift_up(ll i) {
    while (i >= 0 && a[parent(i)] < a[i]) {
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

void insert(ll x) {
    a.push_back(x);
    ll i = a.size() - 1;
    sift_up(i);
}

void heapify(ll i) {
    if (left(i) > a.size() - 1) {
        return;
    }
    ll j = left(i);
    if (right(i) <= a.size() - 1 && a[left(i)] < a[right(i)]) {
        j = right(i);
    }

    if (a[i] < a[j]) {
        swap(a[i], a[j]);
        heapify(j);
    }
}

ll extract_max() {
    ll max = a[0];

    swap(a[0], a[a.size() - 1]);
    a.pop_back();
    if (a.size() > 0) {
        heapify(0);
    }

    return max;
}


ll sum = 0;
void solve(ll m) {
    for (ll i = 0; i < m; i++) {
        ll max = extract_max();
        sum += max;
        insert(max - 1);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        insert(x);
    }

    solve(m);
    cout << sum;
    return 0;
}