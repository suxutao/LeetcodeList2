#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct US {
        vector<int> fa;

        US(int n) : fa(n + 1) {
            for (int i = 0; i <= n; ++i) {
                fa[i] = i;
            }
        };

        int find(int x) {
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        }

        void merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y)
                fa[x] = y;
        }

        bool equal(int x, int y) {
            return find(x) == find(y);
        }
    };

    int minScore(int n, vector<vector<int>> &roads) {
        US us(n);
        vector<int> mn(n + 1, INT_MAX);
        for (auto &i: roads) {
            mn[i[0]] = min(mn[i[0]], i[2]);
            mn[i[1]] = min(mn[i[1]], i[2]);
            us.merge(i[0], i[1]);
        }
        int ans = mn[1];
        for (int i = 2; i <= n; ++i) {
            if (us.equal(1, i)) {
                ans = min(ans, mn[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}