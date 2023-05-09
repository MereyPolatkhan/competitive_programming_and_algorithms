#include <iostream>

using namespace std;

int main(){

    long long n = 3;
    long long m;
    cin >> m;

    long long a[m];
    a[0] = 0;
    a[1] = 2;
    
    for (long long i = 2; i < m; i++) {
        if ((i + 1) % 2 == 1) {
            a[i] = 0;
        }
        else {
            a[i] = a[i - 2] * 2;
        }
    }
    cout << a[m-1];
    // for (int i = 0; i < m; i++) {
    //     cout << a[i] << " ";
    // }

    return 0;
}