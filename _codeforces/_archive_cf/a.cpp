#include <bits/stdc++.h>

using namespace std;

int n;
int calc_max_width(int sum, vector<int>& a) {
    cout << "hi";
    int cur_sum = 0;
    int from = 1;
    int max_w = -1e9;
    for (int i = 1; i <= n; i++) {
        cur_sum += a[i];
        if (cur_sum == sum) {
            max_w = max(max_w, i - from + 1);
            from = i + 1;
            cur_sum = 0;
        }
    }
    if (from == n + 1) {
        return max_w;
    }
    return -1e9;
}

void solve() {
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = 1e9;

    int left_sum = 0;
    int right_sum = 0;

    int i = 1;
    int j = n;

    while (i < j) {
        
    }

}


int main() {

       cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << calc_max_width(11, a);
    return 0;
}