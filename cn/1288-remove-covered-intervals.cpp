#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(),ans=n;
        ranges::sort(intervals,[&](auto&a,auto&b){
            if (a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int mx=intervals[0][1];
        for (int i = 1; i < n; ++i) {
            auto&v=intervals[i];
            if (v[1]<=mx){
                ans--;
            }else{
                mx=v[1];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}