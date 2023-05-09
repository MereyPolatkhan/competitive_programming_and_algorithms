#include <iostream>
#include <queue> 

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue <int> q1;
    queue <int> q2;
    
    int n;
    for(int i = 0; i < 5; i++){
        cin >> n;
        q1.push(n);
    }

    for(int i = 0; i < 5; i++){
        cin >> n;
        q2.push(n);
    }

    int k = 0;

    while(true){
        int q1_frontbek = q1.front();
        int q2_frontbek = q2.front();

        if ((q1_frontbek > q2_frontbek && q1_frontbek != 9 && q2_frontbek != 0) || 
            (q1_frontbek == 0 && q2_frontbek == 9)){
            q1.pop();
            q2.pop();

            q1.push(q1_frontbek);
            q1.push(q2_frontbek);
            
            k++;
        }

        if ((q2_frontbek > q1_frontbek && q2_frontbek != 9 && q1_frontbek != 0) || 
            (q2_frontbek == 0 && q1_frontbek == 9)){
            q1.pop();
            q2.pop();
            
            q2.push(q2_frontbek);
            q2.push(q1_frontbek);
            k++;
        }

        if (q1.empty() == true){
            cout << "second " << k;
            return 0;
        }

        if (q2.empty() == true){
            cout << "first " << k;
            return 0;
        }

        if (k >= 1000000){
            cout << "botva";
            return 0;
        }
    }   


    return 0;
    
    
}