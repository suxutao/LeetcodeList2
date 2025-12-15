#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long getDescentPeriods(vector<int>& prices) {
        ll ans=1,n=prices.size(),cnt=1;
        for (int i = 1; i < n; ++i) {
            if (prices[i]==prices[i-1]-1){
                cnt++;
            }else{
                cnt=1;
            }
            ans+=cnt;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}