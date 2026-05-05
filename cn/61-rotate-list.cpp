#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next)
            return head;
        int n = 0;
        ListNode *p = head, *p2 = head;
        while (p->next) {
            n++;
            p = p->next;
        }
        k %= n + 1;
        if (k == 0)
            return head;
        for (int i = 0; i < n - k; ++i) {
            p2 = p2->next;
        }
        ListNode *ans = p2->next;
        p->next = head;
        p2->next = nullptr;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}