#include <bits/stdc++.h>

using namespace std;

void merge(int * arr, int l, int mid, int r) {
    
    int n = mid - l + 1;
    int m = r - mid;

    int a[n];
    int b[m];

    for (int i = 0; i < n; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < m; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n && j < m) {
        if (a[i] <= b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n) {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < m) {
        arr[k] = b[j];
        k++;
        j++;
    } 
    
}


void merge_sort(int * a, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
    
        merge(a, l, mid, r);
    }

    else {
        return;
    }
}


int main(){

    int n, m;
    cin >> n >> m;

    map<int, int> mp;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];

    merge_sort(a, 0, m - 1);
    
    for (int i = 0; i < m; i++) {
        if (mp[a[i]] > 0) {
            cout << a[i] << " ";
            mp[a[i]]--;
        }
    }

    

    return 0;
}