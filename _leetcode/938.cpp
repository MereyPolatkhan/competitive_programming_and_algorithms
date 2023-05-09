class Solution {
public:
    long long sum = 0;
    void dfs(TreeNode* root, int low, int high) {
        if (root == NULL) return;
        dfs(root->left, low, high);
        if (low <= root->val and root->val <= high){
            sum += root->val;
        }
        dfs(root->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
};