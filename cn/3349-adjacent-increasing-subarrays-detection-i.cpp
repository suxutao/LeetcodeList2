#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),pre=0,cnt=1;
        for (int i = 1; i < n; ++i) {
            if (nums[i]>nums[i-1])
                cnt++;
            else
                pre=cnt,cnt=1;
            if (pre>=k&&cnt>=k||cnt>=k*2)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}