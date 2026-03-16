#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector diag_sum(m + 1, vector<int>(n + 1)); // ↘ 前缀和
        vector anti_sum(m + 1, vector<int>(n + 1)); // ↙ 前缀和
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                diag_sum[i + 1][j + 1] = diag_sum[i][j] + v;
                anti_sum[i + 1][j] = anti_sum[i][j + 1] + v;
            }
        }

        // 从 (x,y) 开始，向 ↘，连续 k 个数的和
        auto query_diagonal = [&](int x, int y, int k) -> int {
            return diag_sum[x + k][y + k] - diag_sum[x][y];
        };

        // 从 (x,y) 开始，向 ↙，连续 k 个数的和
        auto query_anti_diagonal = [&](int x, int y, int k) -> int {
            return anti_sum[x + k][y + 1 - k] - anti_sum[x][y + 1];
        };

        int x = 0, y = 0, z = 0; // 最大，次大，第三大

        auto update = [&](int v) -> void {
            if (v > x) {
                z = y;
                y = x;
                x = v;
            } else if (v < x && v > y) {
                z = y;
                y = v;
            } else if (v < y && v > z) {
                z = v;
            }
        };

        // 枚举菱形正中心 (i,j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(grid[i][j]); // 一个数也算菱形
                // 枚举菱形顶点到正中心的距离 k，注意菱形顶点不能出界
                // i-k >= 0 且 i+k <= m-1，所以 k <= min(i, m-1-i)，对于 j 同理
                int mx = min({i, m - 1 - i, j, n - 1 - j});
                for (int k = 1; k <= mx; k++) {
                    int a = query_diagonal(i - k, j, k); // 菱形右上的边
                    int b = query_diagonal(i, j - k, k); // 菱形左下的边
                    int c = query_anti_diagonal(i - k + 1, j - 1, k - 1); // 菱形左上的边
                    int d = query_anti_diagonal(i, j + k, k + 1); // 菱形右下的边
                    update(a + b + c + d);
                }
            }
        }

        vector<int> ans = {x, y, z};
        while (ans.back() == 0) { // 不同的和少于三个
            ans.pop_back();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}