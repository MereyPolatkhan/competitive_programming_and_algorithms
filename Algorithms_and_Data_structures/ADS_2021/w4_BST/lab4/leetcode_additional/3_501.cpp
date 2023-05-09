// 501. Find Mode in Binary Search Tree


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


  // solution #1 == Hash Map
class Solution {
public:
    
    map<int, int> amp;
    vector<int> vect; 
    
    void dfs(TreeNode* root){
        if (root == NULL){
            return;
        }
        amp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int mx = -1000000;
        for (auto a: amp){
            if (a.second > mx){
                mx = a.second;
                vect.clear();
                vect.push_back(a.first);
            }
            else if (a.second == mx) {
                vect.push_back(a.first);
            }
        }   
        return vect;
    }
    
};

  // solution #2 == without HM 

class Solution {
public:
    vector<int> vect; 
    int cur = 0, prev = 0, mx = 0;
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return vect;      
    }
    
    void dfs(TreeNode* node){
        if (node == NULL){
            return;
        }
        dfs(node->left);

        if (prev == node->val){
            cur++;
        }
        else if (prev != node->val){
            cur = 1;
        }

        if (cur > mx){
            mx = cur;
            vect.clear();
            vect.push_back(node->val);
        }
        else if (cur == mx){
            vect.push_back(node->val);
        }
        prev = node->val;

        dfs(node->right);
    }
};