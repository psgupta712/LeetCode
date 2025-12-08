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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int count = 0;
        ListNode *temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }

        ListNode *curr = head, *prev = NULL;

        k =  k%count;
        if(k==0){
            return head;
        }

        count -= k;
        while(count--){
            prev = curr;
            curr = curr->next;

        }
        prev->next = NULL;
        
        ListNode *tail = curr;
        while(tail->next != NULL){
            tail=tail->next;
        }
        tail->next = head;

        head = curr;
        return head;

    }
};