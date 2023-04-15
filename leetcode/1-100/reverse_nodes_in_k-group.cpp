struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        for (auto p = dummy;;) {
            // check if length bigger or equals to k.
            auto q = p;
            for (int i = 0; i < k && q; i++) q = q->next;
            if (!q) break;
            // reverse k-len linked list.
            auto a = p->next, b = a->next; 
            for (int i = 0; i < k - 1; i++) {
                auto c = b->next;
                b->next = a;
                a = b, b = c;
            }
            // change dummy head to next k-len linked list.
            auto d = p->next;
            p->next = a, d->next = b;
            p = d;
        }

        return dummy->next;
    }
};