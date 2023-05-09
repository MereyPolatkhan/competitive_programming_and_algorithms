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
    int sum = -1e9;
    int dfs(TreeNode* root) { // postorder
        if (root == NULL) {
            return 0;
        }
        
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);

        sum = max(sum, left + right + root->val);

        return max(left, right) + root->val;
    }
    

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
};