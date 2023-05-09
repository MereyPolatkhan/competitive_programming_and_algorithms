#include <iostream> 

using namespace std;


struct Deque{
    int a[100000];
    int st, en;

    Deque(){
        st = 0;
        en = 0;
    }

    void push_center(int x){
        int i_center;
        if ((en - st) % 2 == 0){
            i_center = (en - st) / 2 + st;
        }else{
            i_center = (en - st) / 2 + st + 1;
        }
        for (int i = en - 1; i >= i_center; i--){
            a[i + 1] = a[i];
        }
        a[i_center] = x;
        en++;

    }

    void push_front(int x){
        st--;
        a[st] = x;
    }

    void push_back(int x){
        a[en] = x;
        en++;
    }

    void pop_front(){
        st++;
    } 

    void pop_back(){
        en--;
    } 

    int front(){
        return a[st];
    }

    int back(){
        return a[en-1];
    } 

    int size(){
        return en - st;
    }

    bool empty(){
        return (en == st);
    }

    void show(){
        cout << "en= " << en << endl;
        cout << "st= " << st << endl;
        for (int i = st; i < en; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    } 

};


int main() {

    Deque box;
    
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        char c; 
        cin >> c;
        if (c == '+'){
            int x; cin >> x;
            box.push_back(x);
        }

        if (c == '*'){
            int x; cin >> x;
            box.push_center(x);
        }

        if (c == '-'){
            cout << box.front() << endl;
            box.pop_front();
        }

    }




    return 0;
}