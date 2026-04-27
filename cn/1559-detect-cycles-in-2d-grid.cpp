#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsCycle(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int arr[4][2]{{0,  1},
                      {1,  0},
                      {0,  -1},
                      {-1, 0}};
        vector<vector<bool>> vis(m, vector<bool>(n));
        auto dfs = [&](this auto &&dfs, int x, int y, int ux, int uy, char c) -> bool {
            bool bo = false;
            vis[x][y] = 1;
            for (auto [a, b]: arr) {
                a += x, b += y;
                if (a < 0 || b < 0 || a >= m || b >= n || grid[a][b] != c || a == ux && b == uy)
                    continue;
                if (vis[a][b])
                    return true;
                bo |= dfs(a, b, x, y, c);
            }
            return bo;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    if (dfs(i, j, i, j, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}