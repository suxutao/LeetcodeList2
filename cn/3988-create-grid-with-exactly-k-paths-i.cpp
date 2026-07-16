#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if (m == 1 || n == 1) {
            return k == 1 ? vector<string>(m, string(n, '.')) : vector<string>{};
        }
        if (max(m, n) < k) {
            if (m == 3 && n == 3)
                return {"..#", "...", "#.."};
            return {};
        }
        vector<string> ans(m, string(n, '#'));
        for (int i = 0; i < m; ++i) {
            ans[i][n - 1] = '.';
        }
        for (int i = 0; i < n; ++i) {
            ans[0][i] = '.';
        }
        if (k == 1)
            return ans;
        if (m >= k) {
            for (int i = 0; i < k - 1; ++i) {
                ans[i + 1][n - 2] = '.';
            }
        } else {
            for (int i = 0; i < k - 1; ++i) {
                ans[1][n - 2 - i] = '.';
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}