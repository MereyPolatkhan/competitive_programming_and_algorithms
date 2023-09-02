#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;

set<int> primes;


bool checkPal(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int binaryToDecimal(string binaryString) {
    int decimalNumber = 0;
    int binaryBase = 1; // Represents the current power of 2 for the rightmost bit.

    // Start from the rightmost digit and move to the left.
    for (int i = binaryString.length() - 1; i >= 0; --i) {
        if (binaryString[i] == '1') {
            decimalNumber += binaryBase;
        }
        binaryBase *= 2; // Update the binaryBase for the next iteration.
    }

    return decimalNumber;
}

void SieveOfEratosthenes() {
    int n = (int)2e6;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    // vector<int> res;
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            // cout << p << " ";
            primes.insert(p);
        }
    }
}

bool checkPrime(int n) {
    if (n >= (int)2e6 + 1) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    return primes.count(n);
}

string calc(string original) {
    string s = original;
    int n = s.size();
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (s[i] == '1' and s[j] == '0') {
            s[j] = '1';
        }
        if (s[i] == '0' and s[j] == '1') {
            s[i] = '1';
        }
        i++;
        j--;
    }

    if (checkPal(s) and checkPrime(binaryToDecimal(s))) {
        return s;
    }

    i = 0;
    j = n - 1;

    while (i <= j) {
        if (s[i] == '0' and s[j] == '0') {
            s[i] = '1';
            s[j] = '1';
            if (checkPal(s) and checkPrime(binaryToDecimal(s))) {
                return s;
            }       
        }
        i++;
        j--;
    }
    original += '0';
    return calc(original);
}


int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    SieveOfEratosthenes();

    string s;
    while (cin >> s) {
        cout << calc(s) << "\n";
    }

    return 0;
}

