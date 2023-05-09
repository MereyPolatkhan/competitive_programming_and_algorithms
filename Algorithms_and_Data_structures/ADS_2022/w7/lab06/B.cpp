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

    int n, m;
    cin >> n >> m;
    
    unordered_map<int, int> mp;


    int x; 
    for (int i = 0; i < n; i++){
        cin >> x;
        mp[x]++;
    }
    
    vector<int> res;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (mp[x] != 0) {
            res.push_back(x);
            mp[x]--;
        }
    }


    quick_sort(res, 0, res.size() - 1);
    
    for (auto i: res) cout << i << " ";

    return 0;
}