#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto l = new ListNode(-1);
        auto r = new ListNode(-1);
        
        auto L = l;
        auto R = r;
        while (head) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        r->next = NULL;
        l->next = R->next;

        return L->next;
    }
};

