#include <iostream>

using namespace std;


int main() {

    int n; cin >> n;

    int gold = -1, silver;

    for (int i = 0; i < n; i++){
        int x; cin >> x;

        if (x > gold){
            silver = gold; 
            gold = x;      
        }

        if (silver < x && x < gold) {
            silver = x; 
        }
    }

    cout << silver;

    return 0;
}