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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tail = new ListNode();
        ListNode* con = new ListNode();
        int cnt = 1;
        while(1){
            if(cnt == left){
                tail = curr;
                con = prev;
                prev = curr;
                curr = curr->next;
                cnt++;
                continue;
            }
            if(cnt>=left && cnt<=right){
                ListNode* third = curr->next;
                curr->next = prev;
                prev = curr;
                curr = third;
            }
            if(cnt == right){
                break;
            }
            if(cnt < left || cnt > right){
                prev = curr;
                curr = curr->next;
            }
            cnt++;
        }
        if(con == NULL){
            head = prev;
        }
        if(con != NULL)
            con->next = prev;
        tail->next = curr;
        return head;
    }
};