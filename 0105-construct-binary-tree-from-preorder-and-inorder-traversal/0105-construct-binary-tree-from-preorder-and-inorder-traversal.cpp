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
    

    // TreeNode*build(vector<int>&pre,int preLow,int preHigh,vector<int>&in,int inLow,int inHigh){
    //     // base case
    //     if(preLow > preHigh || inLow > inHigh) return NULL; 
    //     TreeNode*root=new TreeNode(pre[preLow]);
    //     if(preLow == preHigh) return root;
    //     int i=inLow;
    //     // find the 0th element of preOrder in InOrder 
    //     while(i <= inHigh){
    //         if(in[i]==pre[preLow]) break;
    //         i++;
    //     }
    //     int leftCount = i-inLow;
    //     int rightCount = inHigh-1;
    //     // recursion part of left & right subtree
    //     root->left = build(pre, preLow+1, preLow+leftCount, in, inLow, i-1);
    //     root->right = build(pre, preLow+leftCount+1, preHigh, in, i+1, inHigh);
    //     return root;
    // }
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     int n=preorder.size();
    //     return build(preorder,0,n-1,inorder,0,n-1);
    // }

   
    
    TreeNode* myFunc(vector<int> preorder, int prestart, int preend, vector<int> inorder, int instart, int inend, unordered_map<int, int> &mp)
    {
        if(prestart > preend || instart > inend)    return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend)  return root;
        int inroot = mp[root -> val];
        int numsleft = inroot - instart;
        root -> left = myFunc(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, mp);
        root -> right = myFunc(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        TreeNode* ans = myFunc(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return ans;
    }
};