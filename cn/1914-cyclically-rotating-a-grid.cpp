#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m0 = grid.size(), n0 = grid[0].size();
        vector<int> a;
        a.reserve((m0 + n0 - 2) * 2); // 预分配空间

        // 从外到内枚举圈
        for (int i = 0; i < min(m0, n0) / 2; i++) {
            int m = m0 - i * 2, n = n0 - i * 2; // 这一圈的行数和列数
            int x = i, y = i; // 这一圈的左上角
            a.resize(0);
            for (auto& [dx, dy] : DIRS) {
                for (int t = 0; t < n - 1; t++) {
                    a.push_back(grid[x][y]);
                    x += dx;
                    y += dy;
                }
                swap(m, n); // 见 54. 螺旋矩阵 我的题解
            }

            int shift = k % a.size();
            ranges::rotate(a, a.begin() + shift);

            // 注意此时 (x, y) 又回到了左上角
            int j = 0;
            for (auto& [dx, dy] : DIRS) {
                for (int t = 0; t < n - 1; t++) {
                    grid[x][y] = a[j++];
                    x += dx;
                    y += dy;
                }
                swap(m, n);
            }
        }

        return grid;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}