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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first, y = temp.second.second;
            mp[x][y].insert(node -> val);
            if(node -> left != NULL)
            {
                q.push({node -> left, {x - 1, y + 1}});
            }
            if(node -> right != NULL)
            {
                q.push({node -> right, {x + 1, y + 1}});
            }
        }
        for(auto x : mp)
        {
            vector<int> temp;
            for(auto y : x.second)
            {
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};