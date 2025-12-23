#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size(),ans=0;
        ranges::sort(events,[&](auto&a,auto&b){
            if (a[1]==b[1])
                return a[0]<b[0];
            return a[1]<b[1];
        });
        vector<int>pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1]=max(pre[i],events[i][2]);
            int pos= lower_bound(events.begin(), events.end(),events[i][0],[&](auto&a,int val){
                return a[1]<val;
            })-events.begin();
            ans=max(ans,pre[pos]+events[i][2]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}