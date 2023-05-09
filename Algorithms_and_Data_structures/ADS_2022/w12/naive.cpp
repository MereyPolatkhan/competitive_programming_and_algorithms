#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) { // O(n^3)
    int n = s.size();
    vector<int> pi(n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            if (s.substr(0, k) == s.substr(i - k + 1, k))
                pi[i] = k;
        }
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++)
        cout << p[i] << " ";
    return 0;
}