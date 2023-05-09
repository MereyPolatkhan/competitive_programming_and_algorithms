//Задача №755. Хипуй!

#include <iostream> 
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    
    int x;
    int number;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) { // 0=insert
            cin >> number;
            pq.push(number);
        }   
        else if (x == 1) { // 1=extract
            cout << pq.top() << "\n";
            pq.pop();
        } 
    }



    return 0;
}