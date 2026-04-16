#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
        int n = nums.size(), nq = queries.size();
        vector<int> ans(nq, -1);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }
        for (int i = 0; i < nq; ++i) {
            int p = queries[i], t = nums[p], nt = m[t].size();
            if (nt > 1) {
                if (nt == 2) {
                    ans[i] = min(m[t][0] + n - m[t][1], m[t][1] - m[t][0]);
                } else {
                    int pos = lower_bound(m[t].begin(), m[t].end(), p) - m[t].begin();
                    int l = (pos - 1 + nt) % nt, r = (pos + 1) % nt;
                    ans[i] = min((m[t][pos] - m[t][l] + n) % n, (m[t][r] - m[t][pos] + n) % n);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}