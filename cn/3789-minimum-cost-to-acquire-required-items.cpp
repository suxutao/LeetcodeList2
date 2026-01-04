#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth>=cost1+cost2)
            return (ll)cost1*need1+(ll)cost2*need2;
        ll mn=min(need1,need2),ans=mn*costBoth;
        if (need1!=mn){
            ans+=(ll)min(costBoth,cost1)*(need1-mn);
        }
        if (need2!=mn){
            ans+=(ll)min(costBoth,cost2)*(need2-mn);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}