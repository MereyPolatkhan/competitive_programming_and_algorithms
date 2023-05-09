#include <bits/stdc++.h>


using namespace std;





int main() {
 
    int n;
    cin >> n;


    vector< pair <int, int> > a;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());

    int cnt = 1;
    int finish = a[0].first;

    for (int i = 1; i < n; i++) {
        if (finish <= a[i].second) {
            cnt++;
            finish = a[i].first;
        }
    }
    
    cout << cnt;
    
    return 0;
}