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
int camera(TreeNode* root){
        if (root->left==NULL && root->right==NULL){
            root->val= 1; //camera needed : not monitored
            return 0;
        }
        int ans=0;
        int l=2,r=2;    //camera not needed : already monitored
        if (root->left){
            ans += camera(root->left);
            l = root->left->val;
        }
        if (root->right){
            ans += camera(root->right);
            r = root->right->val;
        }
        if (l==1 || r==1){
            root->val = 3;  //if anyone of left or right child needs the camera you buy it
            return (ans+1);
        }
		// camera present
        if (l==3 || r==3){  //either of left or right has a camera so it will monitor you
            root->val = 2; // camera not needed : already monitored
            return ans;
        }
		//if none of the cases satisfy means the curr node is not monitored. So it asks its parent to buy a camera
        root->val=1;
        return ans;
    }
    
    int minCameraCover(TreeNode* root) {
        int ans = camera(root);
        if (root->val == 1){       //special case when the root itself needs monitoring but no parent . So it will buy its own camera
            ans++;
        }
        return ans;
    }
};
