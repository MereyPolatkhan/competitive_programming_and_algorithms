#include <iostream>
#include <cmath>
using namespace std;

int binary_search_counter(int n){
    float a = log2(n);
    if (a > int(a)){
        return int(a) + 1;
    }
    return int(a);
}
int main() {
    int n; cin >> n;
    cout << binary_search_counter(n);

    return 0;
}