class Solution {
public:
    
    void solve(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        for(int i = idx; i < nums.size(); i++)
        {
            if(i > idx && nums[i] == nums[i - 1])  continue;
            temp.push_back(nums[i]);
            solve(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        solve(idx, nums, temp, ans);
        return ans;
    }
};