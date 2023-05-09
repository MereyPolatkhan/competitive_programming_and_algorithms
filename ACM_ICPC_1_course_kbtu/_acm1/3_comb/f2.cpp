#include <iostream>

using namespace std;

long long C(int n,int k)
{
    if ((n==k) || (k==0)) {
        return 1;
    }
    if (k==1) {
        return n;
    }
    return C(n-1,k)+C(n-1,k-1);
}

int main() {
    long long n, k, p, c, t, last = 0;
    cin >> n >> k >> p;
    for (int i = 1; i <= k; i++) {
        for (int it = last + 1; it <= n; it++) {
            c = C(n - it, k - i);

            if (p <= c) {
                cout << it << " ";
                last = it;
                break;
            } else {
                p -= c;
            }

        }
    }
    return 0;
}