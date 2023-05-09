class Solution {
public:
    vector<string> stack;
    vector<string> res;
    
    string join(vector<string> & v) {
        string s = "";
        for (auto i: v) {
            s += i;
        }
        return s;
    }

    vector<string> generateParenthesis(int n) {
        recursion(0, 0, n);
        return res;
    }

    void recursion(int open, int close, int n) {
        if (n == open && open == close) {
            string s = join(stack);
            res.push_back(s);
            return;
        }

        if (open < n) {
            stack.push_back("(");
            recursion(open + 1, close, n);
            stack.pop_back();
        }

        if (close < open) {
            stack.push_back(")");
            recursion(open, close + 1, n);
            stack.pop_back();
        }

    }
};