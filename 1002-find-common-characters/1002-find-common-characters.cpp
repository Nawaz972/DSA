class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        string str = words[0];
        int i = 0, j = 0;
        int n = str.length();
        while(i < n)
        {
            int flag = 0;
            for(int j = 1; j < words.size(); j++)
            {
                string temp = words[j];
                size_t found = temp.find(str[i]);
                if(found == string::npos)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    words[j][found] = '-1';
                }
            }
            if(flag == 0)
            {
                string temp = "";
                temp += str[i];
                ans.push_back(temp);
            }
            i++;
        }
        return ans;
    }
};