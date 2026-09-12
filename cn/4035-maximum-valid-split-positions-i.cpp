#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int f(vector<int>&v) {
        int pre=0,n=v.size(),ans=0;
        vector<int>suf(n+1);
        for (int j = n-1; j >= 0; --j) {
            suf[j]=gcd(v[j],suf[j+1]);
        }
        for (int j = 0; j < n-1; ++j) {
            pre=gcd(pre,v[j]);
            if (pre==suf[j+1])
                ans++;
        }
        return ans;
    }
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size(),ans=0;
        if (n==2)
            return nums[0]==nums[1]?1:0;
        ans=f(nums);
        for (int i = 0; i < n; ++i) {
            vector<int>v(nums);
            v.erase(v.begin()+i);
            ans=max(ans,f(v));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}