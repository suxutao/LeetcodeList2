#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(),pre=0,sum=0,ans;
        vector<int>suf(n+1);
        for (int i = n - 1; i >= 0; --i) {
            suf[i]=suf[i+1]+nums[i];
            sum+=i*nums[i];
        }
        ans=sum;
        for (int i = 0; i < n; ++i) {
            sum=sum-suf[i+1]-pre+(n-1)*nums[i];
            ans=max(ans,sum);
            pre+=nums[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}