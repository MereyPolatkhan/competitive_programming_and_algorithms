#include <bits/stdc++.h>

using namespace std;

vector<int> getdivs(int a, int b) {
    vector<int> res;

    int mn = min(a, b);
    b = max(a, b);
    a = mn;
    vector<int> temp;
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            temp.push_back(i);
            if (i * i != a) temp.push_back(a / i);
        }
    }

    set<int> st;

    for (int n : temp) {
        if (b % n == 0) {
            res.push_back(n);
        }
    }
    sort(res.begin(), res.end());

    return res;
}

int binsearch1(vector<int> & a, int x) {
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            return a[mid];
        }
        else if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (r == -1) return -1;
    return a[r];
}


int main() {
    

    int x, y;
    cin >> x >> y;

    vector<int> a = getdivs(x, y);

    int t;
    cin >> t;
    while (t--) {
        int left, right;
        cin >> left >> right;

        if ((right < a[0]) || (a.back() < left)) {
            cout << -1 << "\n";
        }
        else if (a.back() <= right) {
            cout << a.back() << "\n";
        }
        else {
            if (left < a[0]) {
                cout << binsearch1(a, right) << "\n";
            }
            else {
                int right_boundary = binsearch1(a, right);
                if (right_boundary < left) {
                    cout << -1 << "\n";
                }
                else {
                    cout << right_boundary << "\n";
                }
            }
        }
    }

    return 0;
}