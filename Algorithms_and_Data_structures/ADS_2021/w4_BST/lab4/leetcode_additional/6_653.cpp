/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    bool flag = false;

    bool findTarget(TreeNode* root, int k) {
        dfs(root, k);
        return flag;
    }
    void dfs(TreeNode* node, int k){
        if (node == NULL){
            return;
        }
        int y = k - node->val;
        dfs(node->left, k);

        if (binary_search(v.begin(), v.end(), y) == true){
            flag = true;
            return;
        }
        else{
            v.push_back(node->val);
        }

        dfs(node->right, k);

    }
};