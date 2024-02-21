class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() <= 1)    return nums;
        vector<int> ans(nums.size(), 1);
        vector<int> pre(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        int temp = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            pre[i] = nums[i] * temp;
            temp = pre[i];
        }
        temp = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            post[i] = nums[i] * temp;
            temp = post[i];
        }
        ans[0] = post[1];
        ans[nums.size() - 1] = pre[nums.size() - 2];
        for(int i = 1; i < nums.size() - 1; i++)
        {
            ans[i] = pre[i - 1] * post[i + 1];
        }
        return ans;
    }
};