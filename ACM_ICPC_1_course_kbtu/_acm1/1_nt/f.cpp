#include <bits/stdc++.h>

using namespace std;

long long used[10000070];

void func(){
    long long n = 10000070;

    used[0] = 1;
    used[1] = 1;
    for (long long i = 2; i <= sqrt(n); i++) {
        if (used[i] == 0) {
            for (long long j = i * i; j <= n; j += i) {
                used[j] = 1;
            }
        }
    }
}

int main() {    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    func();

    long long a, b;

    while (cin >> a >> b) {
        long long k = 0;
        for (long long i = a; i <= b; i++) {
            if (used[i] == 0) {
                k++;
            }
        }

        cout << k << "\n\n";
    }


    return 0;
}