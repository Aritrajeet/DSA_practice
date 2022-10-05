// https://leetcode.com/problems/add-one-row-to-tree/


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
    void dfs(TreeNode* root, int val, int currDepth, int depth){
        // base cases
        if(!root) return;
        if(currDepth == depth-1){
            
            // Adding Left node
            TreeNode* leftNode = root->left;
            root->left = new TreeNode(val);
            root->left->left = leftNode;
            
            // Adding right node
            TreeNode* rightNode = root->right;
            root->right = new TreeNode(val);
            root->right->right = rightNode;
        }
        //traversal
        dfs(root->left, val, currDepth+1, depth);
        dfs(root->right, val, currDepth+1, depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        // else
        int currDepth = 1;
        dfs(root, val, currDepth, depth);
        return root;
    }
};
