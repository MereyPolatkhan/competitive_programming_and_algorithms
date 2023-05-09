#include <iostream>
#include <vector>

using namespace std;

vector<int> p_f(string s) { // O(n)
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[i] == s[j]) 
            j = j + 1;
        p[i] = j;
    }
    return p;
}

int main() {
    string s;
    cin >> s;

    vector<int> p = p_f(s);
    for (int i = 0; i < s.size(); i++)
        cout << p[i] << " ";
    // for (int i = 0; i < q.size(); i++) {
    //     cout << p[i] << " ";
    // }
    // for (int i = 0; i < q.size(); i++)
    //     if (p[i] == s.size())
    //         cout << i - 2 * s.size() << " ";
    return 0;
}