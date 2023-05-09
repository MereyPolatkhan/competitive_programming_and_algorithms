#include <iostream>
#include <vector>


using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = p[j - 1];
        }
        if (s[i] == s[j] ){
            j++;
        }
        p[i] = j;
    }
    return p;
}

bool check(string t, string s) {
    string q = t + "$" + s;
    vector<int> p = kmp(q);

    for (int i = t.size(); i < p.size(); i++) {
        if (p[i] == t.size()) {
            return true;
        }
    }
    return false;
}


int main() {
    string A, B;
    cin >> A >> B;

    string a = A;
    string b = B;

    int cnt = 1;

    while (a.size() < b.size()) {
        cnt++;
        a = a + A;
    }

    int j = 0;

    while (check(b, a) == false && j < 2) {
        cnt++;
        a = a + A;
        j++;
    }
    if (j >= 2) cout << -1;
    else cout << cnt;


    return 0;
}