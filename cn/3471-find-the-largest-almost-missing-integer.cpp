#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestInteger(vector<int> &nums, int k) {
        int n = nums.size(), ans = -1;
        unordered_map<int, int> m;
        for (int i = 0; i <= n - k; ++i) {
            vector<int> v;
            for (int j = 0; j < k; ++j) {
                v.push_back(nums[i + j]);
            }
            ranges::sort(v);
            v.erase(ranges::unique(v).begin(), v.end());
            for (int j = 0; j < v.size(); ++j) {
                ++m[v[j]];
            }
        }
        for (auto &[a,b]: m) {
            if (b == 1)
                ans = max(ans, a);
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
