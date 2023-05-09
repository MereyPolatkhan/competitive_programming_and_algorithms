#include <bits/stdc++.h>

using namespace std;

int used[100070];

void primes(int a, int b) {
    // vector<int> p;
    for (int i = 2; i * i <= b; i++) {
        if (used[i] == 0) {
            // p.push_back(i);
            for (int j = i * i; j <= b; j += i) {
                used[j] = 1;
            }
        }
    }
    if (a < 2) a = 2;
    for (int i = a; i <= b; i++) {
        if (used[i] == 0) {
            cout << i << " ";
        }
    }
}

int main() {

    int a, b;
    cin >> a >> b;


    primes(a, b);

    return 0;
}