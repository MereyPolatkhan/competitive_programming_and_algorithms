#include <iostream>

using namespace std;


int beginAB, endAB;
bool AB = false;

int beginBA, endBA;
bool BA = false;

bool func(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s.substr(i, 2) == "AB") {
            beginAB = i;
            endAB = i + 1;
            AB = true;
            break;
        }

        if (s.substr(i, 2) == "BA") {
            beginBA = i;
            endBA = i + 1;
            BA = true;
            break;
        }
    }    

    if (AB == true) {
        for (int i = endAB + 1; i < s.size() - 1; i++) {
            if (s.substr(i, 2) == "BA") {
                BA = true;
                
            }
        }
    }
    else if (BA == true) {
        for (int i = endBA + 1; i < s.size() - 1; i++) {
            if (s.substr(i, 2) == "AB") {
                AB = true;
            }
        }
    }

    if (AB == false || BA == false) return false;
    else return true;
    // return (AB == true && BA == true);
}

int main() {
    string s;
    cin >> s;

    bool a = func(s);
    if (a == true) {
        cout << "YES";
    } 
    else {
        cout << "NO";
    }
    return 0;
}
