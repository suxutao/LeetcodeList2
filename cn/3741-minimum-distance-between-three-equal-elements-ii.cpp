#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumDistance(vector<int> &nums) {
        int ans = INT_MAX, n = nums.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }
        for (auto &[_, v]: m) {
            for (int i = 0; i < (int) v.size() - 2; ++i) {
                ans = min(ans, (v[i + 2] - v[i]) * 2);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}