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
    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == NULL) return right;
        if(right == NULL) return left;
        // Asign lowest value to left
        if(left->val > right->val)
            swap(left, right);
        ListNode* res = left;
        while(left && right) {
            ListNode* temp;
            while(left && left->val <= right->val) {
                temp = left;
                left = left->next;
            }
            temp->next = right;
            swap(left, right);
        }
        return res;
    }
    ListNode* getMid(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* temp = right->next;
        right->next = NULL;
        right = temp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};