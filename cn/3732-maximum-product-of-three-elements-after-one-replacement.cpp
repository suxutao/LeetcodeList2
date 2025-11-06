#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i]=abs(nums[i]);
        }
        ranges::sort(nums,greater<>());
        return (ll)100000*nums[0]*nums[1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}