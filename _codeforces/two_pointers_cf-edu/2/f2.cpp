#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
struct super_stack {
    vector<ll> s, smin, smax;

    void push(ll x) {
        s.push_back(x);
        if (smin.empty()) {
            smin.push_back(x);
        }
        else {
            smin.push_back(::min(smin.back(), x));
        }
        if (smax.empty()) {
            smax.push_back(x);
        }
        else {
            smax.push_back(::max(smax.back(), x));
        }
    }

    ll pop() {
        ll res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }

    bool empty() {
        return s.empty();
    }   

    ll min() {
        return smin.empty() ? LLONG_MAX : smin.back();
    }

    ll max() {
        return smax.empty() ? LLONG_MIN : smax.back();    
    }

};

 
int main() {
 
    ll n, k;
    cin >> n >> k;
 
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
 

    ll l = 0;
    ll cnt = 0;

    super_stack st1, st2;

    for (ll r = 0; r < n; r++) {
        st2.push(a[r]);
        while (max(st1.max(), st2.max()) - min(st1.min(), st2.min()) > k) {
            if (st1.empty()) {
                while (!st2.empty()) {
                    st1.push(st2.pop());
                }
            }
            st1.pop();
            l++;
        }
        cnt += (r - l + 1);
    }

 
    cout << cnt;
 
    return 0;
}
