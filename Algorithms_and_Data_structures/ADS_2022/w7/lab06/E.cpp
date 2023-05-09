#include <bits/stdc++.h>

using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }


    for (int j = 0; j < m; j++) {
        int temp[n];
        for (int i = 0; i < n; i++) {
            temp[i] = a[i][j];
        }    
        quick_sort(temp, 0, n - 1);

        for (int i = 0; i < n; i++) {
            a[i][j] = temp[i];
        }    

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}