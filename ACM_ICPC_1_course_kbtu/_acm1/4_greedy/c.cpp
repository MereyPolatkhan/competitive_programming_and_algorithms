#include <bits/stdc++.h>

using namespace std;

int n, k;
int h_ind(vector<int> & a) {
    int init_h = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= i) init_h = i;
        else break;
    }
    return init_h;
}


int main() {

    cin >> n >> k;
    vector<int> a(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());

    int init_h = h_ind(a);

    if (init_h == n) {
        cout << init_h;
        return 0;
    }

    int j = init_h + 1; 




    while (k > 0 and j >= 1) {
        a[j]++;
        k--;
        j--;
    }       

    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    
    init_h = max(init_h, h_ind(a));


    cout << init_h;


    return 0;
}