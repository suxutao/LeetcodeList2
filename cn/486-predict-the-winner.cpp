#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool predictTheWinner(vector<int> &nums) {
        int n = nums.size();
        if (n % 2 == 0)
            return true;
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        auto dfs = [&](this auto &&dfs, int l, int r) -> int {
            if (l == r)
                return nums[l];
            int &m = memo[l][r];
            if (m != INT_MIN)
                return m;
            m = max(nums[l] - dfs(l + 1, r), nums[r] - dfs(l, r - 1));
            return m;
        };
        return dfs(0, n - 1) >= 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}