#include <iostream> 

using namespace std;

void binary_search(int x, int a[], int n){
    int left = 0;
    int right = n - 1;
    
    while (left <= right){
        int middle = (left + right) / 2;
        if (x == a[middle]){
            cout << "YES\n";
            return;
        }

        else if (x < a[middle]){
            right = middle - 1;
        }

        else if (a[middle] < x){
            left = middle + 1;
        }
    }

    cout << "NO\n";
    return;
}


int main() {

    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x;
    for (int i = 0; i < k; i++){
        cin >> x;
        binary_search(x, a, n);
    }
        

    return 0;
}