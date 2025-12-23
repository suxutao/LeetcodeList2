#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;
    long long minCost(string s, vector<int>& cost) {
        ll sum=0,ans,n=s.size();
        unordered_map<char,ll>m;
        for (int i = 0; i < n; ++i) {
            m[s[i]]+=cost[i];
            sum+=cost[i];
        }
        ans=sum;
        for (auto &[_,a]: m){
            ans=min(ans,sum-a);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}