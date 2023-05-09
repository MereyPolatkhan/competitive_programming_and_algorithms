// 108. Convert Sorted Array to Binary Search Tree


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0){
            return NULL;
        }
        return recursion(nums, 0, sz - 1);
    }
    
    TreeNode* recursion(vector<int>& v, int left, int right){
        if (left > right){
            return NULL;
        }
        int middle = (left + right) / 2;

        TreeNode* node; 
        node = new TreeNode(v[middle]);
        node->left = recursion(v, left, middle - 1);
        node->right = recursion(v, middle + 1, right);
        return node;
    }
};