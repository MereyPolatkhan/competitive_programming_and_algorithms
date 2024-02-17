#include <iostream>
#include <vector>


using namespace std;

size_t m;
string s;
const long long PRIME = 5;
vector<unsigned long long> primePows;
vector<unsigned long long> hashes;

unsigned long long getHash(int l, int r) {
    return hashes[r + 1] - hashes[l] * primePows[r - l + 1];
}

bool checkTwoSubs(int a, int b, int c, int d) {
    return getHash(a, b) == getHash(c, d);
}


int main() {
    #ifdef LOCAL 
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    cin >> s;
    cin >> m;

    hashes.resize(s.length() + 1);
    primePows.resize(s.length() + 1);

    hashes[0] = 0;
    primePows[0] = 1;

    for (int i = 0; i < s.length(); ++i) {
        hashes[i + 1] = hashes[i] * PRIME + s[i];
        primePows[i + 1] = primePows[i] * PRIME;
    }


    cout << "si: ";
    for (int i = 0; i < s.size(); i++) 
        cout << s[i] << " ";
    cout << "\n";

    cout << " i: ";
    for (int i = 0; i < s.size(); i++) 
        cout << i << " ";
    cout << "\n";
    cout << "\n";

    cout << "hashes: \n";
    for (int i = 0; i < hashes.size(); i++)     
        cout << "i: " << i << " = " << hashes[i] << "\n";
    cout << "\n";

 
    cout << "\nprime pows: \n";
    for (int i = 0; i < primePows.size(); i++)     
        cout << "i: " << i << " = " << primePows[i] << "\n";
    cout << "\n";

    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << getHash(a, b) << " == " << getHash(c, d) << " : ";
        cout << (checkTwoSubs(a, b, c, d) ? "Yes\n" : "No\n");
    }

    return 0;
}