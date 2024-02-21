class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        if(n <= 1)  return true;
        while(i <= j)
        {
            while(i < j && !isalnum(s[i]))  i++;
            while(i < j && !isalnum(s[j]))  j--;
            if(i >= j)   return true;
            if(i < j && tolower(s[i]) == tolower(s[j]))
                  {
                cout << s[i] << " " << s[j] << endl;
                      i++;
                      j--;
                  }
                  else  
                  {
                      cout << s[i] << " " << s[j];
                      return false;
                  }
        }
                  return true;
    }
};