#include <bits/stdc++.h> 

using namespace std;
// ------------------------------------
int gcd_euclid(int a, int b){

    if (b == 0) {
        return a;
    }

    return gcd_euclid(b, a % b);
}

int gcd_simple(int a, int b){
    for (int i = min(a, b); i >= 1; i--){
        if (a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}
// ------------------------------------

// Eratosthene || Prime number---------------

void prime_simple(int n){
    for (int i = 2; i <= n; i++){
        bool flag = true;

        for(int j = 2; j * j <= i; j++){
            if (i % j == 0){
                flag = false;
                break;
            }
        }
        
        if (flag){
            cout << i << " ";
        }
    }
} 


int p[100000000];

void prime_eratosthene(int n){
    for (int i = 2; i * i <= n; i++){
        if(p[i] == 0){
            int k = i;
            while(k + i <= n){
                k = k + i; 
                p[k] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++){
        if (p[i] == 0) cout << i << " ";
    }
}
// ------------------------------------------------


void generatePrime(int n) {
    vector<int> used(100000, false);
    for (int i = 2; i * i <= n; i++) {
        if (used[i] == false) {
            for (int j = i + i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (used[i] == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    
    int n;
    cin >> n;

    generatePrime(n);

    return 0;
    
}
 