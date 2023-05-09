#include <bits/stdc++.h>

using namespace std;



vector<int> a(10000, 0);
vector<bool> used(10000, false);
vector<int> res(10000, 0);


int main() {    

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> a[i];


    for (int j = n; j >= 1; j--) {
        if (a[j] == 0) {
            for (int i = n; i >= 1; i--){
                if (used[i] == false) {
                    used[i] = true;
                    res[j] = i;
                    break;
                }
            }
        }
        else{
            int cnt = 0;    
            for (int i = n; i >= 1; i--) {
                if (used[i] == false) {
                    cnt++;
                }
                if (cnt == a[j] + 1) {
                    used[i] = true;
                    res[j] = i;
                    break;
                }
            }

        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }


    return 0;
}