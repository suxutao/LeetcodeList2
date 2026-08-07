#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    vector<int> countTasks(vector<int> &tasks, vector<int> &shifts) {
        int n = shifts.size(), nt = tasks.size();
        ll p = 0;
        vector<int> ans(n);
        vector<ll> pre(nt + 1);
        for (int i = 0; i < nt; ++i) {
            pre[i + 1] = pre[i] + tasks[i];
        }
        for (int i = 0; i < n; ++i) {
            auto pos = upper_bound(pre.begin(), pre.end(), p + shifts[i]);
            if (pos == pre.end()) {
                p = 0;
            } else {
                p += shifts[i];
                ans[i] = pre.end() - pos;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}