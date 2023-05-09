// Задача №1442. Объединение последовательностей

#include <iostream> 

using namespace std;


int main() {
    long long n; cin >> n;

    long long a = 1;
    long long b = 1;

    long long res = -1;

    for (long long i = 1; i <= n; i++) {
        if (a * a == b * b * b) {
            a++;
            i--;
            continue;
        }

        
        if (a * a > b * b * b) {
            res = b * b * b;
            b++;
        }
        
        else if (a * a < b * b * b) {
            res = a * a;
            a++;
        }
        
    }

    cout << res;

    return 0;
}