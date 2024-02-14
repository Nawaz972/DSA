class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)  return strs[0];
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size() - 1];
        string ans = "";
        for(int i = 0; i < min(str1.length(), str2.length()); i++)
        {
            if(str1[i] == str2[i])  ans += str1[i];
            else    return ans;
        }
        return ans;
    }
};