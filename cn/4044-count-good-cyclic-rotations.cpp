#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long sum=0,sum2=0,n=nums.size(),ans=0;
        for (int i = 0; i < n; ++i) {
            sum+=nums[i];
            if (i<n/2)
                sum2+=nums[i];
            nums.push_back(nums[i]);
        }
        ans+=sum2*2>sum;
        for (int i = 0; i < n-1; ++i) {
            sum2+=nums[i+n/2]-nums[i];
            ans+=sum2*2>sum;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}