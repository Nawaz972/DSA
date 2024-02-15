class Solution {
public:
    
    void solve(int idx, vector<int> &candidates, int target, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < candidates.size(); i++)
        {
            if(i > idx && candidates[i] == candidates[i - 1])   continue;
            if(candidates[i] > target)  break;
            nums.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], nums, ans);
            nums.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> nums;
        int idx = 0;
        solve(idx, candidates, target, nums, ans);
        return ans;
    }
};