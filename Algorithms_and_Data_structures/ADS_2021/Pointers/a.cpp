// intro to pointers

#include <iostream>

using namespace std;

int main() {    

    int n = 5;
    cout << &n << endl; // address of variable

    int* ptr = &n; // pointer to address
    cout << ptr << endl;

    cout << *ptr << endl; // 5 (n = 5)
    
    *ptr = 100;

    cout << *ptr << " " << n << "\n\n"; // *ptr = n = 100

    
    
    int v;
    int * ptr2 = &v;
    *ptr2 = 5555;
    cout << v;

    return 0;
}