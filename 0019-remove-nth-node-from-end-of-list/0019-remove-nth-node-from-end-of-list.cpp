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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }

        int pfs = len - n + 1;

        if(pfs == 1){
            ListNode *temp1 = head;
            head = head->next;
            delete temp1;
            return head;
        }

        ListNode *prev = head;
        for(int i=1; i<pfs-1; i++){
            prev = prev->next;
        }
        ListNode *curr = prev->next;
        prev->next = curr->next;
        delete curr;
        return head;
    }
};