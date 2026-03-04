#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    int countSequences(vector<int>& nums, long long k) {
        map<array<ll,3>,ll>m;
        auto dfs=[&](this auto&&dfs,ll i,ll p,ll q)->ll{
            if (i<0){
                return p%q==0&&p/q==k;
            }
            array<ll,3>a{i,p,q};
            if (m.contains(a)){
                return m[a];
            }
            ll ans=0,g=gcd(p*nums[i],q);
            ans+=dfs(i-1,p,q);
            ans+=dfs(i-1,p*nums[i]/g,q/g);
            g=gcd(p,q*nums[i]);
            ans+=dfs(i-1,p/g,q*nums[i]/g);
            return m[a]=ans;
        };
        return dfs(nums.size()-1,1,1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}