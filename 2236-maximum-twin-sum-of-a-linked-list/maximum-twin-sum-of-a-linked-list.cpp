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
        vector<int> vect;
        ListNode* curr = head;

        while (curr != NULL) {
            vect.push_back(curr->val);
            curr = curr->next;
        }
        int result = 0;
        int i = 0;
        int j = vect.size() - 1;

        while (i < j) {
            result = max(result, vect[i] + vect[j]);
            i++;
            j--;
        }
        return result;
    }
};