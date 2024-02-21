class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        string temp = "";
        string ans = "";
        while(i < n)
        {
            temp = "";
            while(i < n && s[i] == ' ') i++;
            while(i < n && s[i] != ' ')     
            {
                temp += s[i];
                i++;
            }
            //cout << temp.length() << endl;
            if(ans == "")   ans = temp;
            else
            {
                if(temp.length() > 0)   ans = temp + " " + ans;
            }
        }
        return ans;
    }
};