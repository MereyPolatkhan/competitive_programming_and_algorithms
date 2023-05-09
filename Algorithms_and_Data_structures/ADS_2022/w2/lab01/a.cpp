#include <bits/stdc++.h>

using namespace std;

void deck(int n) {
    deque<int> d;
    d.push_back(n);
    for (int i = n - 1; i >= 1; i--) {
        d.push_front(i);
        for (int j = 0; j < i; j++) {
            int last = d.back();
            d.pop_back();
            d.push_front(last);
        }
    }

    while (d.size() != 0) {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

int main(){

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        deck(x);
    }

    return 0;
}