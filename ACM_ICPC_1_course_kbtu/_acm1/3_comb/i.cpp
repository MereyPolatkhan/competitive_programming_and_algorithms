#include <bits/stdc++.h>

using namespace std;


int n;
vector<string> a;
int close = 0;
int open = 0;

void gen() {
    if (a.size() == 2 * n) {
        for (string i: a) cout << i;
        cout <<  "\n";
        return;
    }
    else {
        if (open < n) {
            open++;
            a.push_back("(");
            gen();
            a.pop_back();
            open--;
        }
        if (close < open) {
            close++;
            a.push_back(")");
            gen();
            a.pop_back();
            close--;
        }
    }

}


int main() {

    cin >> n;

    gen();

    

    return 0;
}