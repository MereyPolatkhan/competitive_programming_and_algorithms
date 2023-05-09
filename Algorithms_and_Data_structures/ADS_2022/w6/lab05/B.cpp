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

void print() {
    for(auto i: a) cout << i << " "; cout <<"\n";
}

void heapify(ll i) {
    ll lastind = a.size() - 1;

    if (left(i) > lastind) {
        return;
    }

    ll j = left(i);

    if (right(i) <= lastind && a[left(i)] < a[right(i)]) {
        j = right(i); 
    }

    if (a[i] < a[j]) {
        swap(a[i], a[j]);
        heapify(j);
    }
}

ll extract_max() {
    ll mx = a[0];
    swap(a[0], a[a.size() - 1]);

    a.pop_back();

    if (a.size() > 0) {
        heapify(0);
    }
    return mx;  
}

void solve() {
    while (a.size() > 1) {
        ll max1 = extract_max();
        ll max2 = extract_max();

        if (max1 != max2) {
            insert(abs(max1 - max2));
        }
        else {
            insert(0);
        }
    }
}

int main(){

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        insert(x);
    }   

    solve();
    print();

    

    return 0;
}