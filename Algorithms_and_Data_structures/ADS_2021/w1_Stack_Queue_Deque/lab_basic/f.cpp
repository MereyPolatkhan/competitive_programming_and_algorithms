#include <iostream>
#include <stack>

using namespace std;

int main(){

    string s;
    cin >> s;

    stack <char> box;

    for (int i = 0; i < s.length(); i++){
        
        if (s[i] == '{' || s[i] == '[' || s[i] == '('){
            box.push(s[i]);
        }

        else{

            if (box.empty() == true){
                cout << "no";
                return 0;
            }

            else{
                char prev = box.top();
                char current = s[i];

                if (current == ')' && prev == '('){
                    box.pop();
                }
                
                else if (current == ']' && prev == '['){
                    box.pop();
                }
                
                else if (current == '}' && prev == '{'){
                    box.pop();
                }

                else{
                    cout << "no";
                    return 0;
                }
            }
        }

    }

    if (box.empty()== true) {
        cout << "yes";
    }
    else cout << "no";

    return 0;
}