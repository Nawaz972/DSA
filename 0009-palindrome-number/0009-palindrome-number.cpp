class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long num = 0;
        while(n > 0)
        {
            num = num * 10 + n % 10;
            n = n / 10;
        }
        return (num == x);
    }
};