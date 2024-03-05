#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp, vector<string> &ans)
    {
        if(idx == digits.length())
        {
            ans.push_back(temp);
            return;
        }
        string str = mp[digits[idx]];
        for(int i = 0; i < str.length(); i++)
        {
            temp.push_back(str[i]);
            solve(idx + 1, digits, temp, mp, ans);
            temp.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)    return ans;
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";  
        int idx = 0;
        string temp = "";
        solve(idx, digits, temp, mp, ans);
        return ans;
    }
};