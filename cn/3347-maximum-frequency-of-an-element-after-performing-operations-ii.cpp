#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations) {
        int ans = 0, sum = 0;
        unordered_map<int, int> m;
        map<int, int> diff;
        for (auto &i: nums) {
            ++m[i];
            ++diff[i - k];
            --diff[i + k + 1];
            diff[i];
        }
        for (auto &[p, c]: diff) {
            sum += c;
            ans = max(ans, min(m[p] + numOperations, sum));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}