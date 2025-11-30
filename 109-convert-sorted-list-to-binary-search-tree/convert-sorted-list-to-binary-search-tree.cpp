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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);

        ListNode* slow_previous = NULL;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow_previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //  slow mid element ko point kar raha hoga.
        TreeNode* root = new TreeNode(slow->val);
        slow_previous->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};