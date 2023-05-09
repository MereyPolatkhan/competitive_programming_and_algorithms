// 938. Range Sum of BST

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
    int sum = 0;

    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL){
            return 0;
        }
        
        else if (low <= root->val && root->val <= high){
            sum = root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }

        else if (high < root->val){
            sum = rangeSumBST(root->left, low, high);
        }
        
        else if (root->val < low){
            sum = rangeSumBST(root->right, low, high);
        }
        
        return sum;
    }

};