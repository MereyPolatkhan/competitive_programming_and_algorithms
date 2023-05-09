// Accepted

// Задача №99. Поиск подстроки

#include <iostream> 
#include <string.h> 
#include <cmath>

using namespace std;

int p = 29;

int hash_func(string s) {
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * p + (s[i] - 96);
    }
    return h;    
}

int main() {    
    string s, t;
    cin >> s >> t;

    int hash_t = hash_func(t);
    int hash_s = hash_func(s.substr(0, t.size()));

    int pm = 1;
    for (int i = 0; i < t.size() - 1; i++) {
        pm = pm * p;
    }

    // int pm = pow(p, t.size() - 1);

    for (int i = 0; i <= s.size() - t.size(); i++) {
        if (hash_t == hash_s) {
            cout << i << " ";
        }
        hash_s = (hash_s - (s[i] - 96) * pm) * p + (s[i + t.size()] - 96);

    }

    return 0;
}