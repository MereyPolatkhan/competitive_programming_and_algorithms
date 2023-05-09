#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if (n == 1) {
        return false;
    }
    vector<int> prime;
    vector<bool> used(1000000, false);

    for (int i = 2; i <= n; i++) {
        if (used[i] == false){
            prime.push_back(i);
            for (int j = i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }

    return (prime[prime.size() - 1] == n);
}


int main() {

    int n;
    cin >> n;

    if (isPrime(n)) cout << "YES";
    else cout << "NO";

    return 0;
}