#include <iostream> 

using namespace std;

int main() {

    int n; cin >> n;

    int a[n];
    int b[n];

    for (int i = 1; i <= n; i++) {
        a[i - 1] = i * i;
        b[i - 1] = i * i * i;
    }

    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << "\n";

    // for (int i = 0; i < n; i++) cout << b[i] << " ";
    // cout << "\n";

    int i = 0;
    int j = 0;
    int k = 0;
    int c[n * 2];

    while (i < n && j < n) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
            k++;
        }
        else if (a[i] > b[j]) {
            c[k] = b[j];
            j++;
            k++;
        }
        else {
            c[k] = a[i];
            i++;
            j++;
            k++;
        }
    }

    while (j < n) {
        c[k] = b[j];
        k++;
        j++;
    }

    // for (int i = 0; i < k; i++) cout << c[i] << " ";
    // cout << endl;
    
    cout << c[n-1];


    return 0;
}