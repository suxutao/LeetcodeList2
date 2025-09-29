#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        ll sum=nums[0],ans=LLONG_MAX;
        vector<ll>suf(n);
        suf[n-1]=nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i]>nums[i+1]){
                suf[i]=suf[i+1]+nums[i];
            }else{
                break;
            }
        }
        if (suf[1]){
            ans=abs(sum-suf[1]);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i]>nums[i-1]){
                sum+=nums[i];
                if (suf[i+1])
                    ans=min(ans,abs(sum-suf[i+1]));
            }else{
                break;
            }
        }
        return ans==LLONG_MAX?-1:ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}