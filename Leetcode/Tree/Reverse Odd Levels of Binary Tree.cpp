// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

We can solve this problem in 2 easy steps.

Store the level order traversal of the tree in a vector (say v). Note that for odd levels you will need to store it in a seperate vector ( say temp) and then later reverse it and add to v.
Once the vector is ready, you are halfway there. Now, do a level order traversal again keeping track of the index of vector and create an entirely new tree from scratch using the vector v.
NOTE: There maybe better solution in terms of space and time but this is the most intuitive way that one can come accross after seeing the problem.

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v;
        int levels = 0;
        bool isOddLevel = false;
		// level order traversal
        while(!q.empty()){
			//keep the count of levels for later use.
            levels++;
            vector<TreeNode*> temp;
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* curr = q.front();
				// If it is an even level then you simply add it to our main vector v
                if(!isOddLevel)
                    v.push_back(curr);
				// Else add it to a temp vector for now
                else{
                    temp.push_back(curr);
                }
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
			// Now is the time when you will copy the elements from temp vector to the main vector.
            for (int i = temp.size()-1; i>= 0; i--){
                v.push_back(temp[i]);
            }
			// Once the level is processed go for the next level and make it odd/even accordingly
            isOddLevel = !isOddLevel;
        }
        
        //create new binary tree.
        TreeNode* newRoot = root;
        q.push(newRoot);
        int idx = 1;
		// Here we need to run the loop till levels-1 since in each level we are creating nodes for the next level.
        for(int j=0; j<levels-1; j++){
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode *curr = q.front();
                q.pop();
				// idx represents index of the main vector which we traverse together with the level order traversal
                curr->left = v[idx];
                q.push(v[idx++]);
                curr->right = v[idx];
                q.push(v[idx++]);
            }
        }
        return newRoot;
    }
};
