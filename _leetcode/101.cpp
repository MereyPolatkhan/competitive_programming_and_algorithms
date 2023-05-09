class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (q.size() > 0) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            if (left == nullptr and right == nullptr) {
                continue;
            }
            if (left == nullptr or right == nullptr) {
                return false;
            }

            if (left->val != right->val) {
                return false;
            }

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return mirror(root, root);
    }

    bool mirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr and right == nullptr) {
            return true;
        }
        if (left == nullptr or right == nullptr) {
            return false;
        }

        return left->val == right->val and 
                    mirror(left->left, right->right) and
                    mirror(left->right, right->left);
    }
};