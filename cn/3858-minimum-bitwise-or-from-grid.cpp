#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumOR(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), mx = 0, ans = 0;
        for (int i = 0; i < m; ++i) {
            mx = max(mx, ranges::max(grid[i]));
        }
        for (int i = bit_width((unsigned) mx) - 1; i >= 0; --i) {
            int mask = ans | ((1 << i) - 1);
            for (int j = 0; j < m; ++j) {
                bool b = false;
                for (int k = 0; k < n; ++k) {
                    if ((grid[j][k]|mask)==mask){
                        b = true;
                        break;
                    }
                }
                if (!b)
                    ans |= 1 << i;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}