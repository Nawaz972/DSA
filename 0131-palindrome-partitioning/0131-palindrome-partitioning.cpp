class Solution {
public:
    
    bool isPalindrome(string s, int idx, int i)
    {
        while(idx <= i)
        {
            if(s[idx] != s[i])  return false;
            idx++;
            i--;
        }
        return true;
    }
    
    void solve(int idx, string s, vector<string> &temp, vector<vector<string>> &ans)
    {
        //base class
        if(idx == s.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i <= s.size(); i++)
        {
            if(isPalindrome(s, idx, i))
            {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int idx = 0;
        solve(idx, s, temp, ans);
        return ans;
    }
};