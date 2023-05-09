#include <bits/stdc++.h>

using namespace std;

vector<int> eratosphene(int n) {
    vector<int> primes;
    vector<bool> used(n * 10, false);

    for (int i = 3; i <= n; i++){
        if (used[i] == false) {
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }

    return primes;
}

int main() {

    int n;
    cin >> n;

    vector<int> primes = eratosphene(n);

    int l = 0;
    int r = primes.size() - 1;


    while (l <= r) {
        if (primes[l] + primes[r] == n) {
            cout << primes[l] << " " << primes[r];
            return 0;
        }
        else if (primes[l] + primes[r] < n) {
            l++;
        }
        else {
            r--;
        }
    }




    return 0;
}