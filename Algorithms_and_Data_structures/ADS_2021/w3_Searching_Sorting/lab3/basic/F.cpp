#include <iostream>

using namespace std;

int main(){

    int n; cin >> n; 
    int a[n];
    int min = 100;
    int max = -100;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i] == max) a[i] = min;
        cout << a[i] << " ";
    }


    return 0;
}