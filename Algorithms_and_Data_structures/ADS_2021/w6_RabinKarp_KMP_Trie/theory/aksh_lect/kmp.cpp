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
    string s, t;
    cin >> s >> t;

    string q = t + '$' + s;

    vector<int> p = p_f(q);

    for (int i = 0; i < q.size(); i++) cout << p[i] << " ";

    cout << endl;

    for (int i = 0; i < q.size(); i++) {
        if (p[i] == t.size()) {
            cout << i - 2 * t.size() << " " ;
        }
    }



    return 0;
}