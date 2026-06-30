#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxSum(vector<int>& nums, int k, int mul) {
        ll ans=0;
        ranges::sort(nums,greater<>());
        for (int i = 0; i < k; ++i) {
            ans+=(ll)nums[i]*max(1,mul--);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}