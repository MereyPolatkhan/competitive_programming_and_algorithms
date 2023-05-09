#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            a.push_back(i + 1);
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int index; cin >> index;
        cout << a[index - 1] << "\n";
    }

    return 0;
}