// 100%

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

    vector <char> v;
    stack <int> st;

    string s;
    getline(cin, s);


    for (int i = 0; i < s.size(); i++){
        if (int(s[i]) != 32){
            v.push_back(s[i]);
        }
    }

    for(int i = 0; i < v.size(); i++){
        if (v[i] == '+'){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            st.push(first + second);
            
        }
        else if (v[i] == '-'){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            st.push(second - first);
        }

        else if (v[i] == '*'){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            st.push(second * first);
        }

        else {
            st.push(int(v[i]) - 48);
        }

    }

    cout << st.top();
    // A B C + D * +  -->  A + (B + C) * D
    // 7 8 9 + 5 * +  -->  7 + (8 + 9) * 5
    // B C + D *      -->  (B + C) * D

    return 0;
}