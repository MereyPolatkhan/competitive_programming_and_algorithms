#include <bits/stdc++.h>

using namespace std;

vector<int> pile;

void put(int card) {
    for (int i = 0; i < pile.size(); i++) {
        if (pile[i] < card) {
            pile[i] = card;
            return;
        }       
    }

    pile.push_back(card);
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for (int card : a) {
        if (pile.size() == 0) {
            pile.push_back(card);
        }
        else {
            put(card);
        }
    }


    cout << pile.size();


    return 0;
}