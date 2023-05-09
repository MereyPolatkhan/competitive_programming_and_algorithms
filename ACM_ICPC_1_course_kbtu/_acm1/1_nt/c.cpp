#include <bits/stdc++.h>

using namespace std;


int main() {
    // cout << pow(2, 31);
    int n;
    cin >> n;


    
    int k = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                k++;
            }
            else {
                k+=2;
            }
        }
    }
    cout << k;
    
    return 0;
}