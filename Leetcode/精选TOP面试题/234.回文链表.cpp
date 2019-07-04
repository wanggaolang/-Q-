#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        auto r = fs(head);
        r = reverse(r);
        while (head && r) {
            if (r->val != head->val)
                return false;
            r = r->next;
            head = head->next;
        }
        return true;
    }

private:
    ListNode *reverse(ListNode *a) {
        ListNode *l = nullptr, *mid = a, *r = a;
        while (mid) {
            r = r->next;
            mid->next = l;
            l = mid;
            mid = r;
        }
        return l;
    }

    ListNode *fs(ListNode *a) {
        auto fast = a, slow = a;
        while (fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        return slow;
    }

};

int main() {
    auto a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(2);
    a->next->next->next->next = new ListNode(2);
    Solution s;
    if (s.isPalindrome(a))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
