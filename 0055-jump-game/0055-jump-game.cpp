class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fpos = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] + i >= fpos) fpos = i;
        }
        return fpos == 0;
    }
};