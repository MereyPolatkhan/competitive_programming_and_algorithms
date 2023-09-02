#include <bits/stdc++.h>


using namespace std;

const int N = (int)1e6 + 7;

long long calc(long long x) {
    return 2 * x - 1;
}

long long calc_cube(long long h) {
    return calc(h) * calc(h) * 1; 
}


int main() {

    long long n;
    cin >> n;


    vector<long long> a(N, 0);
    a[1] = 1;

    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + calc_cube(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << calc(i) * calc(i) * calc(i) - a[i] << " ";
    }

    return 0;
}