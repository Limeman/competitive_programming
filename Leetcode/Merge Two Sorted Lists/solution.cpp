/*
    Solution to the Merge Two Sorted Lists problem
    https://leetcode.com/problems/merge-two-sorted-lists/
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            return l1;
        }
        else {
            ListNode* head = new ListNode(-1);
            ListNode* walker = head;
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    walker->next = l1;
                    l1 = l1->next;
                }
                else {
                    walker->next = l2;
                    l2 = l2->next;
                }
                walker = walker->next;
            }
            if (l1 != nullptr) {
                walker->next = l1;
            }
            else {
                walker->next = l2;
            }
            return head->next;
        }
    }
};