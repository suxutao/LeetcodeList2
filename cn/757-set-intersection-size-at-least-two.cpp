#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](auto&a,auto&b){
            if (a[1]==b[1])
                return a[0]>b[0];
            return a[1]<b[1];
        });
        int n=intervals.size(),r0=intervals[0][1],r1=intervals[0][1]-1,ans=2;
        for (int i = 1; i < n; ++i) {
            auto&item=intervals[i];
            if (r1>=item[0]){
                continue;
            }else if (r0>=item[0]){
                r1=r0;
                r0=item[1];
                ans++;
            }else{
                r0=item[1];
                r1=item[1]-1;
                ans+=2;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}