class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size() - 1;
        int temp = 0, last = 0;
        if(n + 1 == 1)  return 0;
        for(int i = 0; i < n; i++)
        {
            temp = max(temp, i + nums[i]);
            if(i == last)
            {
                last = temp;
                ans++;
                if(temp >= n)    return ans;
            }
        }
        return ans;
    }
};