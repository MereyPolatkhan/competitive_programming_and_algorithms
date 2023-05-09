// O (N log N + P log N)

#include <iostream>
#include <algorithm> 

using namespace std;

int binary(int n, int a[], int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] <= x) {
            left = mid + 1; 
        }
        else if (x < a[mid]) {
            right = mid - 1;
        }
    }
    return right;
}


int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int prefsum[n + 10];
    prefsum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefsum[i] = prefsum[i-1] + a[i];
    }


    // for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    // for (int i = 0; i < n; i++) cout << prefsum[i] << " "; cout << endl;


    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int index = binary(n, a, p);
        if (index < 0) {
            cout << 0 << " " << 0 << "\n";
        }
        else {
            cout << index + 1 << " " << prefsum[index] << "\n";
        }
    }


    return 0;

}