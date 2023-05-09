#include <bits/stdc++.h> 

using namespace std;

int partition(vector<int> & a, int l, int r) {
    int pi = a[r];
    int i = l;

    for (int j = l; j < r; j++) {
        if (a[j] <= pi) {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}


int part_random(vector<int>& a, int l, int r) {
    srand(time(NULL));
    int p = rand() % (r - l) + l;
    swap(a[p], a[r]);

    return partition(a, l, r);
}

void quick_sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int p = part_random(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quick_sort(a, 0, n - 1);

    int mn = 1e8;

    for (int i = 0; i < n - 1; i++) {
        mn = min(mn, abs(a[i] - a[i + 1]));
    }

    vector<int> res;

    for (int i = 0; i < n - 1; i++) {
        int d = abs(a[i] - a[i + 1]);

        if (d == mn) {
            res.push_back(a[i]);
            res.push_back(a[i + 1]);
        }
    }

    for (auto i: res){
        cout << i << " " ;
    }


    return 0;
}