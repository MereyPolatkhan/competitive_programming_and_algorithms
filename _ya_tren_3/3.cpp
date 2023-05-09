#include <bits/stdc++.h>

using namespace std;


// map<int, int> mp;

int bin_s(int x, vector<int> & a) {
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            while (a[mid] == x and mid < a.size()) {
                mid++;
            }

            return mid;
        }
        else if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }   
   
   
    if (a.size() <= l) {
        return a.size();
    }

    else if (r < 0) {
        return 0;
    }

    return r + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());


    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        cout << bin_s(x, a) << "\n";
    }



    return 0;
}