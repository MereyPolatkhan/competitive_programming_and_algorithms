// Time limit exceeded

// https://vjudge.net/problem/SPOJ-ADACLEAN
#include <iostream> 
#include <map>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> us;

    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        for (int j = 0; j <= n - k; j++) {
            us.insert(s.substr(j, k));
        }
        cout << us.size() << "\n";
        us.clear();
    }
    return 0;
}