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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int first, last, ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
            for(int i = 0; i < size; i++)
            {
                long long idx = q.front().second - mini;
                if(i == 0)  first = idx;
                if(i == size - 1)   last = idx;
                TreeNode* temp = q.front().first;
                q.pop();
                if(temp -> left)    q.push({temp -> left, 2 * idx + 1});
                if(temp -> right)   q.push({temp -> right, 2 * idx + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};