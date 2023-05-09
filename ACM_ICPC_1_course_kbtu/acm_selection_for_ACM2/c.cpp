// Полное решение

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; string s;
        cin >> n >> s;

        if (n != 5) {
            cout << "NO\n";
        }
        else {
            sort(s.begin(), s.end());
            if (s == "Timru") {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}