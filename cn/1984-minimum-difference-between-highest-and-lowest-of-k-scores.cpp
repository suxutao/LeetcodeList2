#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size(),ans=INT_MAX;
        ranges::sort(nums);
        for (int i = k-1; i < n; ++i) {
              ans=min(ans,nums[i]-nums[i-k+1]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}