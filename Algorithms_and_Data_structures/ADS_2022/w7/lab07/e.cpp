#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}   

void merge(vector<pair<int, vector<int>> > & arr, int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    pair<int, vector<int>> L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (cmp(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<pair<int, vector<int>> > & arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
    else {
        return;
    }
}



int main(){

    int n, m;
    cin >> n >> m;
    vector< pair<int, vector<int>> > a;

    for (int i = 0; i < n; i++) {
        vector<int> t;
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            t.push_back(x);
            sum += x;
        }
        a.push_back({sum, t});
    }

    merge_sort(a, 0, a.size() - 1);
    // cout << endl;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].second.size(); j++) {
            cout << a[i].second[j] << " ";

        }
        cout << "\n";
    }

    
    
    return 0;
}