#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <numeric>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <climits>
#include <stack>
 
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;

const int n = 11;
int a[n][n];
int res[n][n];
map<int, pair<int, int>> mp;


void build() {
    // 4
    for (int i = 1, j = 1; j <= 4; j++) {
        res[i][j] = 1;
    }

    // 3
    for (int i = 1, j = 7; j <= 9; j++) {
        res[i][j] = 1;
    }

    // 2
    for (int i = 10, j = 2; j <= 3; j++) {
        res[i][j] = 1;
    }

    // 2
    for (int i = 10, j = 6; j <= 7; j++) {
        res[i][j] = 1;
    }




    // 3
    for (int i = 4, j = 10; i <= 6; i++) {
        res[i][j] = 1;
    }

    // 2
    for (int i = 9, j = 10; i <= 10; i++) {
        res[i][j] = 1;
    }


    res[4][2] = 1;
    res[4][6] = 1;
    res[7][2] = 1;
    res[7][6] = 1;
}

void print() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (res[i][j]) {
                cout << "#";
            }
            else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}


void check(int I, int J) {
    if (1 <= J and J <= 5 && 1 <= I and I <= 2) {
        // cout << "-1-\n";
        for (int i = 1, j = 1; j <= 4; j++) {
            res[i][j] = 0;
        }

        res[I][J] = 1;
        int cnt = 3;

        int j = J - 1;
        while (j >= 1 and cnt) {
            res[I][j] = 1;
            j--;
            cnt--;
        }

        j = J + 1;
        while (j <= 5 and cnt) {
            res[I][j] = 1;
            j++;
            cnt--;
        }
        return;
    }





    if (6 <= J and J <= 10 && 1 <= I and I <= 2) {
        // cout << "-2-\n";

        for (int i = 1, j = 7; j <= 9; j++) {
            res[i][j] = 0;
        }

        res[I][J] = 1;
        int cnt = 2;

        int j = J - 1;
        while (j >= 6 and cnt) {
            res[I][j] = 1;
            j--;
            cnt--;
        }

        j = J + 1;
        while (j <= 10 and cnt) {
            res[I][j] = 1;
            j++;
            cnt--;
        }
        return;
    }





    if (9 <= I and I <= 10 && 1 <= J and J <= 4) {
        // cout << "-3-\n";

        for (int i = 10, j = 2; j <= 3; j++) {
            res[i][j] = 0;
        }

        res[I][J] = 1;
        int cnt = 1;

        int j = J - 1;
        while (j >= 1 and cnt) {
            res[I][j] = 1;
            j--;
            cnt--;
        }

        j = J + 1;
        while (j <= 4 and cnt) {
            res[I][j] = 1;
            j++;
            cnt--;
        }
        return;
    }



    if (9 <= I and I <= 10 && 5 <= J and J <= 8) {
        // cout << "-4-\n";
        for (int i = 10, j = 6; j <= 7; j++) {
            res[i][j] = 0;
        }

        res[I][J] = 1;
        int cnt = 1;

        int j = J - 1;
        while (j >= 5 and cnt) {
            res[I][j] = 1;
            j--;
            cnt--;
        }

        j = J + 1;
        while (j <= 8 and cnt) {
            res[I][j] = 1;
            j++;
            cnt--;
        }
        return;
    }




    if (3 <= I and I <= 7 && 9 <= J and J <= 10) {
        // cout << "-5-\n";

        for (int j = 10, i = 4; i <= 6; i++) {
            res[i][j] = 0;
        }

        res[I][J] = 1;
        int cnt = 2;

        int i = I - 1;
        while (3 <= i and cnt) {
            res[i][J] = 1;
            i--;
            cnt--;
        }

        i = I + 1;
        while (i <= 7 and cnt) {
            res[i][J] = 1;
            i++;
            cnt--;
        }
        return;
    }




    if (8 <= I and I <= 10 && 9 <= J and J <= 10) {
        // cout << "-6-\n";

        for (int j = 10, i = 9; i <= 10; i++) {
            res[i][j] = 0;
        }

        res[I][J] = 1;
        int cnt = 1;

        int i = I - 1;
        while (8 <= i and cnt) {
            res[i][J] = 1;
            i--;
            cnt--;
        }

        i = I + 1;
        while (i <= 10 and cnt) {
            res[i][J] = 1;
            i++;
            cnt--;
        }
        return;
    }



    if (1 <= J and J <= 3 and 3 <= I and I <= 5) {
                // cout << "-7-\n";
        res[4][2] = 0;
        res[I][J] = 1;
        return;
    }


    if (4 <= J and J <= 8 and 3 <= I and I <= 5) {
                // cout << "-8-\n";
        res[4][6] = 0;
        res[I][J] = 1;
        return;
    }
 
    if (1 <= J and J <= 3 and 6 <= I and I <= 8) {
                // cout << "-9-\n";
        res[7][2] = 0;
        res[I][J] = 1;
        return;
    }

    if (4 <= J and J <= 8 and 6 <= I and I <= 8) {
                // cout << "-10-\n";
        res[7][6] = 0;
        res[I][J] = 1;
        return;
    }
}

void solve() {
    
    build();

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int x;
            cin >> x;

            a[i][j] = x;
            mp[x] = {i, j};
        }       
    }

    int i = mp[100].first, j = mp[100].second;
    if (res[i][j]) {
        print();
        return;
    }

    check(i, j);

    print();
}

/*  things to check:
    !  freopen
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

int main() { 
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #else
    freopen("battleship.in", "r", stdin);
    freopen("battleship.out", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

