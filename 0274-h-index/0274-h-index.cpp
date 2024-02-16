class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> arr(n + 1, 0);
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] >= n)   arr[n]++;
            else    arr[citations[i]]++;
        }
        for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
        int cnt = 0;
        for(int i = n; i >= 0; i--)
        {
            cnt += arr[i];
            if(cnt >= i) return i;
            // cnt += arr[i];
        }
        return cnt;
    }
};