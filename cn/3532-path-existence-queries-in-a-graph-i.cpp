#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct US {
        vector<int> fa;

        US(int n) : fa(n) {
            for (int i = 0; i < n; ++i) {
                fa[i] = i;
            }
        }

        int query(int x) {
            return fa[x] == x ? x : fa[x] = query(fa[x]);
        }

        void merge(int x, int y) {
            x = query(x);
            y = query(y);
            if (x != y)
                fa[x] = y;
        }

        bool connect(int x, int y) {
            return query(x) == query(y);
        }
    };

    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {
        vector<bool> ans;
        US us(n);
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff)
                us.merge(i, i + 1);
        }
        for (auto &q: queries) {
            ans.push_back(us.connect(q[0], q[1]));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}