/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || (head->next == NULL))
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                break;
        }

        if (slow != fast)
            return NULL;

        ListNode* R = head;
        while (R != slow) {
            R = R->next;
            slow=slow->next;
        }
        return R;
    }
};