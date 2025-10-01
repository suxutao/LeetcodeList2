#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        ll ans=0;
        ranges::sort(nums);
        for (int i = 0; i < n; ++i) {
            int l=lower_bound(nums.begin(), nums.end(),lower-nums[i])-nums.begin();
            int r=lower_bound(nums.begin(), nums.end(),upper-nums[i]+1)-nums.begin();
            if (i>=l&&i<=r)
                ans+=r-l-1;
            else
                ans+=r-l;
        }
        return ceil(ans/2.);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}