class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        while(i < s.length())
        {
            if((i + 1) < s.length())
            {
                if(mp[s[i]] >= mp[s[i + 1]])
                {
                    ans += mp[s[i]];
                    i++;
                }
                else
                {
                    ans += mp[s[i + 1]] - mp[s[i]];
                    i += 2;
                }
            }
            else   
            {
                ans += mp[s[i]];
                break;
            }
        }
        return ans;
    }
};