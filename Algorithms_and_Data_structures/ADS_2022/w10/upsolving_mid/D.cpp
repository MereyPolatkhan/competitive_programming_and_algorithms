#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> prime;

    for (int number = 2; number <= n; number++) {
        if (n % number == 0) {
            prime.push_back(number);
            while (n % number == 0) {
                n = n / number;
            }
        }
    }

    // for (auto i: prime) cout << i << " " ;
    cout << prime.size();
 
    return 0;
}