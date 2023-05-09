#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool used[100000];

vector<int> generatePrime(int n) {
    vector <int> prime;
    for (int i = 2; i <= n; i++) {
        if (used[i] == false) {
            prime.push_back(i);
            for (int j = i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }
    return prime;
}

int main(){

    int n;
    cin >> n;

    vector<int> superPrime;
    vector<int> prime = generatePrime(n * 40);

    for (int i = 0; i < prime.size(); i++) {
        if (binary_search(prime.begin(),  prime.end(), i + 1)) {
            // cout << i + 1 << " ";
            superPrime.push_back(prime[i]);
        }
    } 
    // for (auto i: superPrime) cout << i << " ";  cout << endl;
    cout << superPrime[n-1];

    return 0;
}