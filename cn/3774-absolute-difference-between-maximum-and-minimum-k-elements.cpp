#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int da=0,xiao=0,n=nums.size();
        ranges::sort(nums);
        for (int i = 0; i < k; ++i) {
            xiao+=nums[i];
            da+=nums[n-i-1];
        }
        return da-xiao;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}