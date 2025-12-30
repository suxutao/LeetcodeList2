#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        ll sum=0,ans=LLONG_MIN;
        vector<int>mn(n);
        mn[n-1]=nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            mn[i]=min(mn[i+1],nums[i]);
        }
        for (int i = 0; i < n-1; ++i) {
            sum+=nums[i];
            ans=max(ans,sum-mn[i+1]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}