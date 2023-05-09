#include <iostream> 
#include <queue>
using namespace std;

int main(){

    queue <int> first, second;

    for (int i = 0; i < 5; i++){
        int x; cin >> x;
        first.push(x);
    }

    for (int i = 0; i < 5; i++){
        int x; cin >> x;
        second.push(x);
    }

    int k = 0;
    while(true){
        if (first.empty() == true){
            cout << "second " << k;
            return 0;
        }
        if (second.empty() == true){
            cout << "first " << k;
            return 0;
        }
        if (k >= 1000000){
            cout << "botva";
            return 0;
        }

        // first > second
        if (first.front() == 0 && second.front() == 9) {            
            
            first.push(second.front());
            first.push(first.front());

            first.pop(); 
            second.pop();
        }

        // second > first
        else if (second.front() == 0 && first.front() == 9) {

            second.push(first.front());
            second.push(second.front());
            
            first.pop(); 
            second.pop();
        }

        // first > second
        else if(first.front() > second.front()){
            
            first.push(second.front());
            first.push(first.front());

            first.pop(); 
            second.pop();
        }

        else if(second.front() > first.front()){
            second.push(first.front());
            second.push(second.front());
            
            first.pop(); 
            second.pop();
        }
        k++;

    }



    return 0;
}