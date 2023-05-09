#include <iostream>
#include <queue>
using namespace std; 

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    queue <string> q9, q10, q11;

    int grade; string name;
    while(cin >> grade >> name){
        if (grade == 9){
            q9.push(name);
        }

        if (grade == 10){
            q10.push(name);
        }

        if (grade == 11){
            q11.push(name);
        }
    }


    while(q9.empty() == false){
        cout << 9 << " " << q9.front() << "\n";
        q9.pop();
    }

    while(q10.empty() == false){
        cout << 10 << " " << q10.front() << "\n";
        q10.pop();
    }

    while(q11.empty() == false){
        cout << 11 << " " << q11.front() << "\n";
        q11.pop();
    }

    return 0;
}