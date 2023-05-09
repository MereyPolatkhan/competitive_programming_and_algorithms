#include <bits/stdc++.h> 

using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int random(int arr[], int low, int high) {
    srand(time(NULL));
    int random_num = rand() % (high - low) + low;
    
    swap(arr[random_num], arr[high]);
    return partition(arr, low, high);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int p = random(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}


int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;   
}