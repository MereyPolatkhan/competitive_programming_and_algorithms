#include <iostream> 

using namespace std;

int gcd_simple(int a, int b){
    for (int i = min(a, b); i >= 1; i--){
        if (a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 1;
}

int euclid(int a, int b){

    if (b == 0){
        return a;
    }

    return euclid(b, a % b);
} 


int main() {

    int a, b;
    cin >> a >> b;

    cout << euclid(a, b);



    return 0;
}