// prime: 2 ways: 
//          1) O(sqrt(n)) 
//          2) Eratosphene 


#include <bits/stdc++.h>

using namespace std;



bool check_if_prime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false; // Prime emes
        }
    }

    return true;
}

// n = 100
 // sqrt(n) = 10 
    // 1 2 4 5 10 20 50 100

void simple(int k) {
    for (int i = 1; i <= k; i++) {
        if (check_if_prime(i) == true) {
            cout << i << " ";
        }
    }
}






void eratosphene(int n) {
    // 25 -> 2 3 5 7 11 13 17 19 23

    // 25->     2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    //marked    1 1 1 1 1 0 1 1 1  0  1  0  1  1  1  0  1  1  1  1  1  0  1  1   
    //          

    vector<bool> marked(n + 2, 0);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (marked[i] == false) {
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                marked[j] = true;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++) cout << primes[i] << " ";

}


int main() {
    int k;
    cin >> k;

    simple(k);
    cout << "\n";
    eratosphene(k);

    return 0;
}