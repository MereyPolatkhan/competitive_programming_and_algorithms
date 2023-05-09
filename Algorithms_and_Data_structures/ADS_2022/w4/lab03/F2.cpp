// O(P*N)

#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;

        int count = 0;
        int sum = 0;

        for (int j = 0; j < n; j++) {
            if (p >= a[j]) {
                count++;
                sum += a[j];
            }
        }
        cout << count << " " << sum << "\n";
    }



    return 0;
}