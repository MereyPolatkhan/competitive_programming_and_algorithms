#include <bits/stdc++.h>

using namespace std;


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

    vector<int> a = {1, 3, 7, 10};
    int t; cin >> t;
    cout << binsearch1(a, t);


    return 0;
}