/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp != NULL)
        {
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        int ans = INT_MIN;
        while(temp != NULL)
        {
            int sum = temp -> val + st.top();
            ans = max(ans, sum);
            temp = temp -> next;
            st.pop();
        }
        return ans;
    }
};