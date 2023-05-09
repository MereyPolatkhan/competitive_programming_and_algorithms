// self implementation

#include <iostream>
using namespace std;

struct Stack {
	int a[1000];
	int n;
	Stack() {
		n = 0;
	}

	int size() {
		return n;
	}

	void push(int x) {
		a[n] = x;
		n++;
	}

	void pop() {
		if (n == 0) {
			cerr << "My error: trying to pop empty stack\n";
			exit(0);
		}
		n--;
	}

	int top() {
		return a[n-1];
	}

    void clear() {
        n = 0;
    }

    bool empty(){
        return (n == 0);
    }

};

int main() {
    Stack st;
    string k;

    while(true){
        cin >> k;
        if(k == "push"){
            int x;
            cin >> x;
            st.push(x);
            cout << "ok\n";
        }
        if(k == "pop"){
            if(st.size() > 0){
                cout << st.top() << "\n";
                st.pop();
            }
            else{
                cout << "error\n";
            }
        }
        if(k == "size"){
            cout << st.size() << "\n";
        }
        if(k == "back"){
            if(st.size() > 0){
                cout << st.top() << "\n";
            }
            else{
                cout << "error\n";
            }
        }
        if(k == "clear"){
            while (!st.empty()){
                st.pop();
            }
            cout << "ok\n";
        }
        if(k == "exit"){
            cout << "bye\n";
            return 0;
        }
    }   

	return 0;
}



