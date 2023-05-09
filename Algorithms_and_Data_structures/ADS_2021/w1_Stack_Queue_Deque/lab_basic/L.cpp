#include <iostream>

using namespace std;
// #define int long long 

long long euclid(long long a, long long b){
    if (b == 0){
        return a;
    }
    return euclid(b, a % b);
} 


int main(){

    long long a, b;
    cin >> a >> b;

    long long product = a * b;
    
    cout << product / euclid(a, b);

    return 0;
}