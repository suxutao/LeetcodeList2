#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        int bmx = 0;
        vector<int> pmx(m + 1);
        vector<vector<int>> u2d(m + 1, vector<int>(n + 1));
        vector<vector<int>> d2u(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    u2d[i + 1][j + 1] = 1 + min({u2d[i][j + 1], u2d[i + 1][j], u2d[i][j]});
                }
            }
            pmx[i + 1] = max(pmx[i], ranges::max(u2d[i + 1]));
        }
        for (int i = m - 1; i > 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j]) {
                    d2u[i][j] = 1 + min({d2u[i][j + 1], d2u[i + 1][j], d2u[i + 1][j + 1]});
                }
            }
            bmx = max(bmx, ranges::max(d2u[i]));
            ans = max(ans, min(pmx[i], bmx));
        }

        int rmx = 0;
        vector<int> lmx(n + 1);
        vector<vector<int>> l2r(n + 1, vector<int>(m + 1));
        vector<vector<int>> r2l(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[j][i]) {
                    l2r[i + 1][j + 1] = 1 + min({l2r[i][j + 1], l2r[i + 1][j], l2r[i][j]});
                }
            }
            lmx[i + 1] = max(lmx[i], ranges::max(l2r[i + 1]));
        }
        for (int i = n - 1; i > 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (mat[j][i]) {
                    r2l[i][j] = 1 + min({r2l[i][j + 1], r2l[i + 1][j], r2l[i + 1][j + 1]});
                }
            }
            rmx = max(rmx, ranges::max(r2l[i]));
            ans = max(ans, min(lmx[i], rmx));
        }

        return ans * ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}