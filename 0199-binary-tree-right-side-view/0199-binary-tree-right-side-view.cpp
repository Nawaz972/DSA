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
    
    void solve(TreeNode* root, int idx, map<int, int> &mp)
    {
        if(root == NULL)    return;
        if(mp.find(idx) == mp.end())
        {
            mp[idx] = root -> val;
        }
        solve(root -> right, idx + 1, mp);
        solve(root -> left, idx + 1, mp);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;
        int idx = 0;
        solve(root, idx, mp);
        for(auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};