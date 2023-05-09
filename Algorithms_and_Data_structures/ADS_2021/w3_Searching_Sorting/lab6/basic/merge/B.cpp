// Задача №766. Сортировка слиянием
#include <bits/stdc++.h> 

using namespace std;

void mergebek_sortkhanov(int a[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int left_Array[left_size];
    int right_Array[right_size];

    for (int i = 0; i < left_size; i++) {
        left_Array[i] = a[left + i];
    }

    for (int i = 0; i < right_size; i++) {
        right_Array[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < left_size && j < right_size) {
        if (left_Array[i] <= right_Array[j]) {
            a[k] = left_Array[i];
            i++;
        }
        else {
            a[k] = right_Array[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        a[k] = left_Array[i];
        i++;
        k++;
    }
    while (j < right_size) {
        a[k] = right_Array[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = (left + right) / 2;
    
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);

    mergebek_sortkhanov(a, left, mid, right);
}

int main() {

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
