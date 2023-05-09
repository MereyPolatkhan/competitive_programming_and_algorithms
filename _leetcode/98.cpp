class Solution {
public:
    bool flag = true;
    bool isValidBST(TreeNode* root) {
        func(root, nullptr, nullptr);
        return flag;
    }

    void func(TreeNode* root, TreeNode* minimum, TreeNode* maximum) {
        if (root == nullptr) {
            return;
        }

        if ((minimum != nullptr and minimum->val >= root->val) ||
            (maximum != nullptr and maximum->val <= root->val)) {
            flag = false;
            return;
        }

        func(root->left, minimum, root);
        func(root->right, root, maximum);
    }
};