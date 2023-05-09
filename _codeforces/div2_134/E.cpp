#include <iostream> 
#include <vector> 
#include <stdio.h>

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    // freopen("input.txt", "r", stdin);


    string s;
    cin >> s; // scanf("%s", &s); 
    int n = s.size();

    int q;
    cin >> q; // scanf("%d", &q);
    
    string t, nw; 
    while (q--) {
        cin >> t;// scanf("%s", &t);

        nw = s + t;

        vector<int> pf = p_f(nw);
        for (int j = n; j < pf.size(); j++) {
            printf("%d ", pf[j]);
        }
        printf("\n");
    }

    return 0;
}