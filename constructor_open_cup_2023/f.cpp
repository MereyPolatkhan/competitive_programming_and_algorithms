#include <bits/stdc++.h>

using namespace std;

void solve() {

    string s;
    cin >> s;

    int n = s.size();

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') a[i] = 1;
        else a[i] = 2;
    }



    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        swap(a[i], a[i + 1]);
        if (a[i] == 1 and a[i + 1] == 1 and a[i + 2] == 1) {
            cout << "Alice\n";
            return;
        }
        if (a[i + 1] == 1 and a[i + 2] == 1 and a[i + 3] == 1) {
            cout << "Alice\n";
            return;
        }   

        if (flag == true){
            swap(a[i], a[i + 1]);
            continue;
        }

        if  (((a[i] == 2 and a[i + 1] == 2 and a[i + 2] == 2) 
                or 
                (a[i + 1] == 2 and a[i + 2] == 2 and a[i + 3] == 2))){
            swap(a[i], a[i + 1]);
            continue;
        }

        else {
            flag = true;
            continue;
        }
    }


    if (flag == false) {
        cout << "Bob\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        swap(a[i], a[i + 1]);
        if (a[i] == 2 and a[i + 1] == 2 and a[i + 2] == 2) {
            cout << "Bob\n";
            return;
        }
        if (a[i + 1] == 2 and a[i + 2] == 2 and a[i + 3] == 2) {
            cout << "Bob\n";
            return;
        }   
    }

}

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}