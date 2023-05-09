#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int hh1; char c1; int mm1;
    cin >> hh1 >> c1 >> mm1;


    int hh2; char c2; int mm2;
    cin >> hh2 >> c2 >> mm2;

    int res = 0;
    
    if (hh1 > hh2) {
        if (mm1 > mm2) {
            res = 24 - hh1 + hh2 - 1 + 60 - mm1 + mm2;
        }
        else { // mm1 <= mm2 
            res = 24 - hh1 + hh2 + mm2 - mm1;
        }
    }

    else if (hh1 == hh2) {
        if (mm1 > mm2) {
            res = 23 + 60 - (mm1 - mm2);
        }
        else {
            res = mm2 - mm1;
        }
    }

    else {
        // cout << res;
        if (mm1 > mm2) {
            while (hh1 < hh2 - 1) {
                res++;
                hh1++;
            }
            res += 60 - mm1 + mm2;
        }
        else {
            res = hh2 - hh1 + mm2 - mm1;
        }
    }

    cout << res;
    return 0;
}