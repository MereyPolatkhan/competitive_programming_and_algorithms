// Accepted
#include <iostream> 
#include <vector>
using namespace std;

vector<int> p_f(string a, string b) { // O(n)
    string s = b + '$' + a;
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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {    
        string a, b;
        cin >> a >> b;
        
        vector<int> p = p_f(a, b);
        vector<int> res;

        for (int j = b.size() + 1; j < p.size(); j++) {
            if (p[j] == b.size()) {
                res.push_back(j - b.size() * 2 + 1);
            }
        }
        
        if (res.size() == 0){
            cout << "Not Found\n";
        }
        else {
            cout << res.size() << "\n";
            for (int j = 0; j < res.size(); j++) cout << res[j] << " ";
        }
    }

    return 0;
}