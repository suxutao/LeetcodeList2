#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mx=0,mn=INT_MAX;
        for (auto &i: nums){
            mx=max<ll>(i,mx);
            mn=min<ll>(i,mn);
        }
        return (mx-mn)*k;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}