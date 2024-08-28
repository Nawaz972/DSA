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
    
    TreeNode* solve(vector<int> inorder, int instart, int inend, vector<int> postorder, int poststart, int postend, unordered_map<int, int> &mp)
    {
        if(instart > inend || poststart > postend)  return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int idx = mp[postorder[postend]];
        root -> left = solve(inorder, instart, idx - 1, postorder, poststart, poststart + idx -instart - 1, mp);
        root -> right = solve(inorder, idx + 1, inend, postorder, poststart + idx - instart, postend - 1, mp);
        return root;
        // if(poststart == postend)    return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        TreeNode* ans = solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
        return ans;
    }
};