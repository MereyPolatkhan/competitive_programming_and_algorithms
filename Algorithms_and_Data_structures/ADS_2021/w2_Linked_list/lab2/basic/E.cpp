#include <iostream> 
#include <map> 
#include <vector>


using namespace std;

int main() {

    char c;
    int x;
    map <int, int> m;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> c >> x){
        if (c == '+'){
            m[x]++;
        }

        else if(c == '-'){
            if (m[x] == 0 || m.size() == 0){
                cout << "ERROR";
                return 0;
            }
            m[x]--;
        }
    }

    int k = 0;
    for(auto i: m){
        if (i.second == 0){
            k++;
        }
    }   

    if (k == m.size()){
        cout << "EMPTY";
        return 0;
    }
    
    for(auto it: m)
        for(int i = 0; i < it.second; i++)
            cout << it.first << " ";
    

    return 0;
}