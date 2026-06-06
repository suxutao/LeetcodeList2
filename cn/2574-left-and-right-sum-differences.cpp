#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size(),sum=accumulate(nums.begin(), nums.end(),0),pre=0;
        vector<int>ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i]=abs(sum-pre*2-nums[i]);
            pre+=nums[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}