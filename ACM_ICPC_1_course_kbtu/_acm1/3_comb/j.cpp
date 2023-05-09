#include <bits/stdc++.h>

using namespace std;


int n;
int curSum = 0;

vector<vector<int>> rs;

void gen(vector<int> a, int j) {
    if (curSum > n) {
        return;
    }
    if (curSum == n) {
        reverse(a.begin(), a.end());
        // for (int i : a) cout << i << " "; cout << '\n';
        rs.push_back(a);
        return;

    }
    else {
        for (int i = j; i <= n; i++) {
            if (curSum + i > n) {
                break;
            }
            curSum += i;
            a.push_back(i);
            gen(a, i);
            curSum -= i;
            a.pop_back();
        }
        return;
    }
    
}


int main() {

    cin >> n;
    vector<int> a;
    gen(a, 1);


    sort(rs.begin(), rs.end());
    for (auto i: rs) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }



    return 0;
}