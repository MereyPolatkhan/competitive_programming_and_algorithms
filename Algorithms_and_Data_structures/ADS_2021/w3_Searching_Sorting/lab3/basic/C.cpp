#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int max = a[0];
    int index = 0;

    for (int i = 1; i < n; i++){
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }

    cout << index + 1;

    return 0;
}