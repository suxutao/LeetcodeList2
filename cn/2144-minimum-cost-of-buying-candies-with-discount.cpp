#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0,n=cost.size();
        ranges::sort(cost,greater<>());
        for (int i = 0; i < n; ++i) {
            if (i%3!=2)
                ans+=cost[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}