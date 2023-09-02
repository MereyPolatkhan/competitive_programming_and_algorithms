#include <bits/stdc++.h>

using namespace std;


int MOD = (int)1e9 + 7;
long long cnt = 0;

bool contain(vector<int> &a, int n) {
    for (int &x: a) {
        if (x == n) {
            return true;
        }
    }
    return false;
}

bool check(vector<int> & nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}
set<vector<int>> st;
void perm(vector<int> & a, vector<int> & temp) {
    if (a.size() == temp.size()) {
        if (check(temp)) {
            // for (int i : temp) {
            //     cout << i << " ";
            // }
            // cout << "\n";
            st.insert(temp);
            cnt++;
        }        
    }
    else {
        for (int n: a) {
            if (contain(temp, n) == false) {
                temp.push_back(n);
                perm(a, temp);
                temp.pop_back();
            }
        }
    }
}

int specialPerm(vector<int>& a) {
    vector<int> temp;
    
    perm(a, temp);
    
    return (cnt % MOD);
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    specialPerm(a);
    cout << "cnt: " << st.size() << "\n\n";
    for (auto i: st) {
        for (int j: i) cout << j << " "; cout << "\n";
    }

    return 0;
}

