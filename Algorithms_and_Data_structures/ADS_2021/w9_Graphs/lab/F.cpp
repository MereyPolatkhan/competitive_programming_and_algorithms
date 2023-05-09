// https://plusplustmustlive4.blogspot.com/2020/03/151.html?view=flipcard
#include <bits/stdc++.h> 

using namespace std;

vector<pair <int, int> > v;
int color[11111];
int n, m;
int k = 0;

bool analysis(int t) {
    for (int i = t; i < m; i++) {
        int a = v[i].first;
        int b = v[i].second;

        if (color[a] == 0){
            if (color[b] == 0) {
                
                color[a] = 1;
                color[b] = -1;

                if (analysis(i + 1) == false) {
                    color[a] = -1;
                    color[b] = 1;
                    return analysis(i + 1);
                }

            }
            else if (color[b] != 0) {
                color[a] = -color[b];
            }
            k++;
        }

        else if (color[a] != 0){
            if (color[b] == 0) {
                color[b] = -color[a];
            }
            else if (color[b] != 0) {
                if (color[a] == color[b]){
                    return false;
                }
            }
        }
    }

    return true;
}


int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    // if (n == 1) {
    //     cout << "YES\n"; 
    //     return 0;
    // }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v.push_back({x, y});
    }

    if (analysis(0) == true) {
        cout << "YES\n";
        cout << k;
    }
    else {
        cout << "NO\n";
    }


    // for (int i = 0; i < n; i++) {
    //     cout << i + 1 << " = " << color[i] << endl;
    // }


    return 0;
}