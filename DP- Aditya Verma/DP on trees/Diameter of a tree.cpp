//Non - DP solution : O(n2)    
int height(Node* root){     //height calculation takes O(n)
        if (root == NULL ) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {      //We call height for all nodes. So O(n*f(height)) = O(n2)
        if (root == NULL) return 0;
        int d1 = 1 + height(root->left) + height(root->right);      //consider that diameter is pivoted on curr root
        return max(d1,max(diameter(root->left),diameter(root->right)));     //if d1 is not max means either of left or right subtree will have pivot for diameter 
    } 
//Now, we can eliminate calling the height function again and again using DP

//DP approach
  int res = 0;
    int solve(Node* root){
        if (root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        
        int temp = 1 + max(l,r);  //Here itself we are adding 1 so we calculate the height along with diameter
        int ans = max(temp,1+l+r);  //temp is max when diameter is not pivot on this root . If it is pivot then left height + right height + curr root will be the diameter
        res = max(res,ans);  //calculate max of all the diameter of subtrees till it reaches the actual root. This will give the diameter of the tree as the whole
        return temp;  //returning temp will ensure the height is updated
    }
    int diameter(Node* root) {
        solve(root);
        return res;
    }
//Since we call solve() for each node only once T.C. = O(n)
