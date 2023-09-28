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
private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* left = head;
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        right = reverseList(right);
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(left || right) {
            if(left) {
                temp->next = left;
                left = left->next;
                temp = temp->next;
            }
            if(right) {
                temp->next = right;
                right = right->next;
                temp = temp->next;
            }
        }
        head = dummy->next;
    }
};