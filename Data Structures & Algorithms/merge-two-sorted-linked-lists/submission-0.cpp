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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp;
        auto node = &temp;
        auto a = list1, b = list2;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                node->next = a;
                a = a->next;
            } else {
                node->next = b;
                b = b->next;
            }
            node = node->next;
        }

        node->next = a != nullptr ? a : b;
        return temp.next;
    }
};
