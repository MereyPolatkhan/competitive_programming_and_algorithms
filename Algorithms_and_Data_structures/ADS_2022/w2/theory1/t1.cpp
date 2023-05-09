#include <bits/stdc++.h>

using namespace std;

void factorization(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1) cout << n << " ";
} 

int main() {

    int n;
    cin >> n;

    factorization(n);

    return 0;
}