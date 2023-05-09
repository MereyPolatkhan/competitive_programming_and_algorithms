#include <bits/stdc++.h>

using namespace std;


int main() {
    // freopen("input.txt", "r", stdin);

    deque<int> a, b;
    
    for (int i = 1; i <= 10; i++) {
        int x;
        cin >> x;
        if (i <= 5) {
            a.push_back(x);
        }
        else {
            b.push_back(x);
        }
    }



    int k = 0;
    int mx = 1e6;

    while (a.size() > 0 && b.size() > 0 && k < mx) {
        int fst = a.front();
        int scd = b.front();
        a.pop_front();
        b.pop_front();

        if (scd > fst) {
            if (scd == 9 and fst == 0) {
                // a win
                a.push_back(fst);
                a.push_back(scd);
            }
            else {
                // b win    
                b.push_back(fst);
                b.push_back(scd);
            }
        }
        else {
            if (fst == 9 and scd == 0) {
                // b win    
                b.push_back(fst);
                b.push_back(scd);    
            }
            else {
                // a win
                a.push_back(fst);
                a.push_back(scd);
            }
        }
        k++;
        // cout << k << " ";
        // for (int i : a) cout << i << " "; cout << "\n";
        // for (int i : b) cout << i << " "; cout << "\n";

    } 

    if (k == mx) {
        cout << "botva";
    }
    else {
        if (a.size() == 0) cout << "second " << k << "\n";
        else cout << "first " << k << "\n";
    }


    return 0;
}