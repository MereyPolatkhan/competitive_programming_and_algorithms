#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; 
        cin >> n;
        vector<int> v;
        int a = 1;
        while (n != 0) {
            int san = n % 10;
            // cout << "san * a = " << san*a << endl;
            if (san != 0) {
                v.push_back(san * a);
            } 
            a = a * 10;
            n = n / 10;
        }

        cout << v.size() << "\n";
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << "\n";

    }

    return 0;
}