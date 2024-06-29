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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            size++;
            temp = temp -> next;
        }
        size /= 2;
        if(size == 0)   return head -> next;
        temp = head;
        int cnt = 1;
        while(cnt < size)   
        {
            temp = temp -> next;
            cnt++;
        }
        temp -> next = temp -> next -> next;
        return head;
    }
};