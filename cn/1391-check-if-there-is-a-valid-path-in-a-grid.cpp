#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static constexpr int DIRS[7][2][2] = {
            {},
            {{0, -1}, {0, 1}},  // 站在街道 1，可以往左或者往右
            {{-1, 0}, {1, 0}},  // 站在街道 2，可以往上或者往下
            {{0, -1}, {1, 0}},  // 站在街道 3，可以往左或者往下
            {{0, 1}, {1, 0}},   // 站在街道 4，可以往右或者往下
            {{0, -1}, {-1, 0}}, // 站在街道 5，可以往左或者往上
            {{0, 1}, {-1, 0}},  // 站在街道 6，可以往右或者往上
    };

    // 判断街道 street 是否包含移动方向 (dx, dy)
    bool contains(int street, int dx, int dy) {
        auto& ds = DIRS[street];
        return ds[0][0] == dx && ds[0][1] == dy ||
               ds[1][0] == dx && ds[1][1] == dy;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector vis(m, vector<int8_t>(n));

        auto dfs = [&](this auto&& dfs, int x, int y) -> bool {
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            vis[x][y] = true; // 标记 (x, y) 访问过，从而避免重复访问
            for (auto& [dx, dy] : DIRS[grid[x][y]]) { // 枚举下一步往哪走
                int i = x + dx, j = y + dy;
                if (0 <= i && i < m && 0 <= j && j < n && !vis[i][j] &&
                    contains(grid[i][j], -dx, -dy) && dfs(i, j)) {
                    return true;
                }
            }
            return false;
        };

        return dfs(0, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}