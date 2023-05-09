#include <bits/stdc++.h>


using namespace std;

int find_index(int a[], int x, int n){ 
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}

void change(int * a, int i, int j) {
    if (j > i) {
        
    }
    else if (j < i) {

    }
    else {
        return;
        
    }
}

int main() {

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    

    int b[n]; 
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int j = find_index(a, b[i], n);

        change(a, i, j);
    }

    return 0;
}