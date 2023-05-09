#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a[1000000];
ll n;

unordered_set<ll> indexes;
unordered_set<ll> getters;

void fill_indexes() {
    for (ll i = 1; i <= n; i++) {
        if (a[i] == 0) {
            indexes.insert(i);
        }
    }
}

void fill_getters() {
    for (ll i = 1; i <= n; i++) {
        getters.insert(i);
    }

    for (ll i = 1; i <= n; i++) {
        if (a[i] != 0) {
            getters.erase(a[i]);
        }
    }
}

void fill_a() {
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
}

unordered_map<ll, ll> pairs;
vector<pair<ll, ll>> ahah;


void fill_ahah() {

    for (auto i: pairs) {
        ahah.push_back({i.first, i.second});
    }

    for (ll i = 0; i < ahah.size(); i++) {
        if (ahah[i].first == ahah[i].second) {
            if (i == 0) {
                ll cur = ahah[i].second;
                ahah[i].second = ahah[i + 1].second;
                ahah[i+1].second = cur;
            }
            else {
                ll cur = ahah[i].second;
                ahah[i].second = ahah[i - 1].second;
                ahah[i-1].second = cur;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill_a();
    fill_getters();
    fill_indexes();

    for (ll index: indexes) {
        for (ll getter: getters) {
            // cout << index << " " << getter << "\n";
            if (index != getter) {
                pairs[index] = getter;
                getters.erase(getter);
                break;
            }
            
            else if (getters.size() == 1) {
                pairs[index] = getter;
            }
        }
    }


    // cout <<"\n\nPAIRS";

    // for (auto i: pairs) {
    //     cout << i.first << " " << i.second << "\n";
    // }
    
    // cout <<"\n\n";


    fill_ahah();

    // cout <<"\n\nahahs";

    // for (auto i: ahah) {
    //     cout << i.first << " " << i.second << "\n";
    // }
    
    // cout <<"\n\n";


    for (auto i: ahah) {
        a[i.first] = i.second;
    }

    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}