#include <iostream>

using namespace std;

string func(string s) {
    int between = s.size() - 2;
    string newstr = s[0] + to_string(between) + s[s.size() - 1];
    return newstr;
}

int main() {
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() > 10) {
            cout << func(s) << "\n";
        }
        else {
            cout << s << "\n";
        }
    }
    
    
    return 0;
}