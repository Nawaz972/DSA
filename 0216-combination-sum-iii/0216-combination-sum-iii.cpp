#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(int idx, int k, int n, int sum, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(k == 0)
        {
            if(n == sum)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(sum > n) return;
        for(int i = idx; i < 10; i++)
        {
            temp.push_back(i);
            sum = sum + i;
            k = k - 1;
            solve(i + 1, k, n, sum, temp, ans);
            sum = sum - i;
            k = k + 1;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 1;
        int sum = 0;
        solve(idx, k, n, sum, temp, ans);
        return ans;
    }
};