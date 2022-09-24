// https://leetcode.com/problems/path-sum-ii/


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
    vector<vector<int>> ans;
    void solve(TreeNode* root, int target, vector<int> &temp , int sum){
        if(!root) return;
        if(!root->left and !root->right and sum == target){   // if a leaf node and meets the target then its one of the answers
            ans.push_back(temp);
            return;
        }
      // backtracking for both left and right nodes
        if(root->left){
            temp.push_back(root->left->val);
            solve(root->left,target,temp,sum + root->left->val);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->right->val);
            solve(root->right,target,temp,sum + root->right->val);
            temp.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        if(!root) return ans;
        temp.push_back(root->val);      // root will always be in all the answers.
        solve(root, targetSum, temp,root->val);
        return ans;
    }
};
