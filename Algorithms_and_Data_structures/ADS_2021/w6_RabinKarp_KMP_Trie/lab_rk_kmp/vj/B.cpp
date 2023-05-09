// Accepted 
// https://codeforces.com/problemset/problem/4/C
#include <iostream> 
#include <map>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    
    map<string, int> mp;

    int n; cin >> n;
    
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (mp[s] == 0) {
            cout << "OK\n";
        }
        else {
            cout << s + to_string(mp[s]) << "\n";
        }
        mp[s]++;
    }

    return 0;
}
