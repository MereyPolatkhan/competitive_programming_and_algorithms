#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> d;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.push_back(x);
        while (d.back() - d.front() > 3000) {
            d.pop_front();
        }
        cout << d.size() << " ";
    }

    return 0;
}