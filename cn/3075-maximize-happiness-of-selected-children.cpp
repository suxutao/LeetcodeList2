#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll ans=0;
        ranges::sort(happiness,greater<>());
        for (int i = 0; i < k; ++i) {
            ans+=max(0,happiness[i]-i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}