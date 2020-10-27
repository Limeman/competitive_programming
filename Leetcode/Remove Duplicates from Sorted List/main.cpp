/*
    Solution to the Remove Duplicates from Sorted List problem
    https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* H = head;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        else {
            ListNode* walker = head->next;
            while (true) {
                if (walker != nullptr && head->val == walker->val) {
                    ListNode* tmp = walker->next;
                    head->next = tmp;
                    walker->next = nullptr;
                    delete walker;
                    walker = tmp;
                }
                else {
                    walker = walker->next;
                    head = head->next;
                }
                if (walker == nullptr) {
                    return H;
                }
            }
        }
    }
};