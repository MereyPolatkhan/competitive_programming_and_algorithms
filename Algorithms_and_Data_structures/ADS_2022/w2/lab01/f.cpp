#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k;
    cin >> k;

    int n = k * 8;

    vector<bool> used(n + 1, 0);
    vector<int> prime;

    for (int i = 2; i <= n; i++) {
        if (used[i] == false) {
            prime.push_back(i);
            for (int j = i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }


    // for (auto i: prime) cout << i << " ";
    // cout << endl;
    cout << prime[k-1];

    return 0;
}