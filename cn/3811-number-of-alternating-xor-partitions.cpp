#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int alternatingXOR(vector<int> &nums, int target1, int target2) {
        constexpr int MOD = 1'000'000'007;
        int last1, last2;
        unordered_map<int, int> f1;
        unordered_map<int, int> f2 = {{0, 1}};
        int pre_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre_sum ^= nums[i];
            last1 = f2[pre_sum ^ target1];
            last2 = f1[pre_sum ^ target2];
            f1[pre_sum] = (f1[pre_sum] + last1) % MOD;
            f2[pre_sum] = (f2[pre_sum] + last2) % MOD;
        }
        return (last1 + last2) % MOD;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}