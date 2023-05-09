#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;

    while (cin >> n) {

        vector< pair <double, int> > a;

        for (int i = 0; i < n; i++) {
            double kun, penalty;
            cin >> kun >> penalty;

            a.push_back({kun / penalty, i + 1});
        }

        sort(a.begin(), a.end());

        for (auto i : a) {
            cout << i.second << " ";
        }
        cout << "\n";
    }

    return 0;
}