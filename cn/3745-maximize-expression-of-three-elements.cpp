#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n=nums.size();
        ranges::sort(nums);
        return nums[n-1]+nums[n-2]-nums[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}