#include <bits/stdc++.h> 

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}



int count(int n) {
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i * j) / gcd(i, j) / gcd(i, j) <= 3) {
                k++;
            }
        }
    }
    return k;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    // freopen("input.txt", "r", stdin);


    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; 
        cin >> n;

        cout << n << " " << count(n) << "\n";
    }


    return 0;
}