#include <bits/stdc++.h>

using namespace std;


int count(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}





int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    
    cout << count(n) << "\n";
    
    return 0;
}