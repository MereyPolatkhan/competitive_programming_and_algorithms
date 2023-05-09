#include <iostream>
#include <vector>
#include <math.h>


using namespace std;


vector<int> factorization(int n) {
    
    vector<int> fact;
    
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            fact.push_back(i);
            n = n / i;
        }
    }

    return fact;
}

bool check(int n){
    int k = 0;
    for (int i = 2; i <= (n/2); i++) {
        if (n % i == 0) {
            k++;
        }
    }
    return k == 2 || k == 1;
}

int main() {

    int n;
    cin >> n;

    vector<bool> used(n + 1, 0);
    vector<int> prime(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (used[i] == false) {
            prime[i] = i;
            for (int j = i; j <= n; j += i) {       
                used[j] = true;
            }
        }
    } // ln(n) * n

    

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (prime[i] == 0) {
            if (check(i)) {
                // cout << i << " ";
                k++;
            }
        }
    }

    cout << "\n" << k;
    return 0;
}