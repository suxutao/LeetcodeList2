#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for (auto &i: queries) {
            pre[i[0]][i[1]]++;
            pre[i[2] + 1][i[3] + 1]++;
            pre[i[0]][i[3] + 1]--;
            pre[i[2] + 1][i[1]]--;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i && j) {
                    ans[i][j] = pre[i][j] + ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
                } else if (i || j) {
                    if (i) {
                        ans[i][j] = pre[i][j] + ans[i - 1][j];
                    } else {
                        ans[i][j] = pre[i][j] + ans[i][j - 1];
                    }
                } else {
                    ans[i][j] = pre[i][j];
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