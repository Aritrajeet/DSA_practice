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
    
int solve(TreeNode* root,int &res)
    {
        // Base Case 
        if(root==NULL) return NULL;
        int ls = solve(root->left,res);
        int rs = solve(root->right,res);
        int temp = max(max(ls,rs)+root->val,root->val);     //either the max sum will go through the left or right subtree of the node or will only end in this node.
        int ans = max(temp,ls+rs+root->val);    //either it will be pivoted on this node i.e. max path will be left subtree sum + right subtree sum + node sum or it will be the above case
        res = max(res,ans);     //Finally, get max of all subtree max path sum and when root is reached we have max path sum of whole tree
        return temp;      
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
