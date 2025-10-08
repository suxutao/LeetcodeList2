#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for (int i = 0; i < n; ++i) {
            if (i&1)
                ans-=nums[i];
            else
                ans+=nums[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}