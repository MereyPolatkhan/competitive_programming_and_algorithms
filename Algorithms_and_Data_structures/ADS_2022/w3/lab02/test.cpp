#include <iostream>
#include <map>


using namespace std;




int main(){

    int n;
    cin >> n;

    map<int, int> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    map<int, int> :: iterator it;

    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }

}
