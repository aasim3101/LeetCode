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
    ListNode* leftPointer = new ListNode();
    bool stop=false;
    bool backtrack=false;
    void helper(int left, int right, ListNode* rightPointer){
        if(right == 1){
            return;
        }
        rightPointer=rightPointer->next;
        if(left > 1){
            leftPointer=leftPointer->next;
        }
        helper(left-1,right-1,rightPointer);
        if(rightPointer == leftPointer || rightPointer->next == leftPointer){
            stop=true;
        }
        if(!stop){
            int t=leftPointer->val;
            leftPointer->val=rightPointer->val;
            rightPointer->val=t;
            leftPointer=leftPointer->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        leftPointer = head;
        ListNode* rightPointer = head;
        helper(left, right, rightPointer);
        return head;
    }
};