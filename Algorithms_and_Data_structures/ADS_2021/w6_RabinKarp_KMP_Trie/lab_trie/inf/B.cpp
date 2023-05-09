#include <iostream> 
#include <vector> 

using namespace std;

vector<int> pf(string s) {
    int n = s.size();
    vector<int> p(n);

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }   

    return p;
}

int main() {
    freopen("inputik.txt", "r", stdin);
    // freopen("outputik.txt", "w", stdout);
    string s;
    cin >> s;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string sub;
        cin >> sub;

        vector<int> p = pf(sub + "$" + s);
        vector<int> res;
        int k = 0;
        for (int j = 0; j < p.size(); j++) {
            if (p[j] == sub.size()) {
                k++;
                res.push_back(j - sub.size() * 2 + 1);
            }
        }
        cout << k << " ";
        for (int l = 0; l < res.size(); l++) cout << res[l] << " ";
        cout << "\n";

    }

    return 0;
}