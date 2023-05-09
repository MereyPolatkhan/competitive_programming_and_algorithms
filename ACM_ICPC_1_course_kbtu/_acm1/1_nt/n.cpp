#include <bits/stdc++.h>

using namespace std;

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}


vector<int> a(100000, 0);

void fill() {
    int n = 10000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

    }




    return 0;
}