#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int minimumK(vector<int>& nums) {
        ll l=1,r=100000,n=nums.size();
        auto check=[&](ll x)->bool {
            ll sum=0,ji=x*x;
            for (int i = 0; i < n; ++i) {
                sum+=ceil((double)nums[i]/x);
                if (sum>ji)
                    return false;
            }
            return true;
        };
        while (l<r){
            ll mid=(l+r)>>1;
            if (!check(mid)){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}