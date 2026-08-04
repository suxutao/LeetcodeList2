#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                ans=max(ans,(ll)nums[i]*nums[j]/gcd(nums[i],nums[j])/gcd(nums[i],nums[j]));
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}