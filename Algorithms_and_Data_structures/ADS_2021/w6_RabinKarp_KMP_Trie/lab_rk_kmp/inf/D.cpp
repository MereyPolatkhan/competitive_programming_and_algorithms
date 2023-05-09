// Accepted
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;   
    
    int n = s.size();

    int a[n];
    a[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = a[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = a[j - 1];
        }
        
        if (s[i] == s[j]) j++;
        
        a[i] = j;
    }   

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}