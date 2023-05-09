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
    while (i >= 0 && a[parent(i)] < a[i]){
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

void insert(ll x) {
    a.push_back(x);
    ll lastind = a.size() - 1;
    sift_up(lastind);
}

int solve() {
    int k = 0;
    int l = a.size() - 1;
    for (int i = 0; i < a.size(); i++) {
        if (left(i) <= l && right(i) <= l) {
            if (a[left(i)] < a[right(i)]) {
                k++;
            }
        }
    }
    return k;
}


int main(){

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        insert(x);
    }   

    cout << solve();
    

    return 0;
}