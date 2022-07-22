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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* con = NULL;
        ListNode *temp = NULL;
        bool first = true;
        bool firstBig = true;
        while(curr != NULL){
            ListNode* third = curr->next;
            if(curr->val < x){
                if(first){
                    first = false;
                    if(prev != NULL){
                        prev->next = third;
                    }
                    temp = curr;
                    head = curr;
                }
                else{
                    if(prev != NULL){
                        prev->next = third;
                    }
                    temp->next = curr;
                    temp = curr;
                }
                curr = third;
            }
            else{
                if(firstBig){
                    firstBig = false;
                    con = curr;
                }
                prev = curr;
                curr = third;
            }
        }
        if(temp != NULL){
            temp->next = con;
        }
        return head;
    }
};