#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long gcdSum(vector<int>& nums) {
        ll n=nums.size(),mx=nums[0],ans=0;
        vector<ll>prefix(n);
        for (int i = 0; i < n; ++i) {
            mx=max<ll>(mx,nums[i]);
            prefix[i]=gcd(nums[i],mx);
        }
        ranges::sort(prefix);
        ll l=0,r=n-1;
        while (l<r){
            ans+=gcd(prefix[l],prefix[r]);
            l++;r--;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}