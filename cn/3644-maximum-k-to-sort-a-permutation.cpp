#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size(),ans=-1;
        for (int i = 0; i < n; ++i) {
            if (nums[i]!=i)
                ans&=nums[i];
        }
        return max(ans,0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}