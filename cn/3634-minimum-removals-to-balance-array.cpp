#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size(),ans=n-1;
        ranges::sort(nums);
        for (int i = 0; i < n; ++i) {
            long long temp=(long long)nums[i]*k;
            int pos=upper_bound(nums.begin(), nums.end(),temp)-nums.begin();
            ans=min(ans,n-pos+i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}