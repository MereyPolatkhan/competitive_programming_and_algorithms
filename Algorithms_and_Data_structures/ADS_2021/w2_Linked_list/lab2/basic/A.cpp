#include <iostream> 
#include <map>

using namespace std;

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> b;

    string s;
    while(cin >> s){
        b[s] += 1;
    }
    
    map<string, int> :: iterator it = b.begin();
    while(it != b.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}