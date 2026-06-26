#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size(),n=units[0].size(),mn=INT_MAX,mn1=INT_MAX;
        ll ans=0;
        if (n==1){
            for (int i = 0; i < m; ++i) {
                ans+=units[i][0];
            }
            return ans;
        }
        for (int i = 0; i < m; ++i) {
            ranges::sort(units[i]);
            mn1=min(mn1,units[i][1]);
            mn=min(mn,units[i][0]);
            ans+=units[i][1];
        }
        ans-=mn1-mn;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}