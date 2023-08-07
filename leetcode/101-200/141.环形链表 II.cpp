#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return NULL;

        auto slow = head;
        auto fast = head;

        while (true) {
            if (!fast || !fast->next) return NULL;
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};