// Задача №1418. Разные

#include <iostream>

using namespace std;

void quick_sort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    int pivot = a[mid];

    int i = left, j = right;
        
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (pivot < a[j]) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }        

    quick_sort(a, left, j);
    quick_sort(a, i, right);
}


int main() {

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    quick_sort(a, 0, n - 1);

    int k = 1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            k++;
        }
    }

    cout << k;
    return 0;
}