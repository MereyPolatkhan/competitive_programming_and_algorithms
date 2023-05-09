// Задача №756. Минимум в окне

#include <bits/stdc++.h> 

using namespace std;

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, k;
    cin >> n >> k;

    int a[n];
    multiset<int> mst;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < k - 1; i++) {
        mst.insert(a[i]);
    }

    for (int i = 0; i < n - k + 1; i++) {
        mst.insert(a[i + k - 1]);
        cout << *mst.begin() << "\n";
        mst.erase(mst.find(a[i]));
    }



    return 0;
}
