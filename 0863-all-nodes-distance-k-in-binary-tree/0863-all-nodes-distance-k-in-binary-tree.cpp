/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp1)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp -> left)
            {
                mp1[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right)
            {
                mp1[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp1;
        makeParents(root, mp1);
        unordered_map<TreeNode*, bool> mp2;
        int dis = 0;
        queue<TreeNode*> q;
        q.push(target);
        mp2[target] = true;
        while(!q.empty())
        {
            int n = q.size();
            if(dis++ == k) break;
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left && !mp2[temp -> left])
                {
                    mp2[temp -> left] = true;
                    q.push(temp -> left);
                }
                if(temp -> right && !mp2[temp -> right])
                {
                    mp2[temp -> right] = true;
                    q.push(temp -> right);
                }
                if(mp1[temp] && !mp2[mp1[temp]])
                {
                    mp2[mp1[temp]] = true;
                    q.push(mp1[temp]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr -> val);
        }
        return ans;
    }
};