#include <bits/stdc++.h>


using namespace std;

typedef long long ll;



bool func(ll char_hp, ll char_att, ll mon_hp, ll mon_att) {

    ll k = min(mon_hp / char_att, char_hp / mon_att);

    mon_hp = mon_hp - (char_att * k);
    if (mon_hp <= 0) {
        return true;
    }
    char_hp = char_hp - (mon_att * k);
    if (char_hp <= 0) {
        return false;
    }
    while (mon_hp > 0) {
        if (char_hp <= 0) {
            return false;
        }
        mon_hp -= char_att;
        char_hp -= mon_att;
    }
    // cout << "here\n";
    return true;
}

void solve() {
    ll char_health, char_attack;
    ll monster_health, monster_attack;
    ll k, attack_increase, health_increase;

    cin >> char_health >> char_attack;
    cin >> monster_health >> monster_attack;
    cin >> k >> attack_increase >> health_increase;

    bool flag = false;

    for (int i = 0; i <= k; i++) {
        flag = func(char_health + health_increase * (k - i), 
                            char_attack + attack_increase * i, 
                            monster_health, 
                            monster_attack);

        if (flag) {
            cout << "YES\n";
            return;
        }
        
    }

    cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}