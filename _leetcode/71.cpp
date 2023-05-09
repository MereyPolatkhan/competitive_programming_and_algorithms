class Solution {
public:
    string simplifyPath(string path) {
        vector<string> a;
        string cur = "";
        path += '/';
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                a.push_back(cur);
                cur = "";
            }
            else {
                cur += path[i];
            }
        }
        
        stack<string> st;
        for (auto el: a) {
            if (el == "..") {
                if (st.size() > 0) st.pop();
                else continue;
            }
            else if (el == "." || el == "") continue;
            else st.push(el);
        }   

        a.clear();
        while (st.size() > 0) {
            a.push_back(st.top());
            st.pop();
        }

        string res = "";
        for (int i = a.size() - 1; i >= 0; i--){
            res += "/" + a[i];
        }
        return res.size() > 0 ? res : "/";
    }
};