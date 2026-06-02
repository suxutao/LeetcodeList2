#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land=INT_MAX,water=INT_MAX,ans=INT_MAX;
        int n=landStartTime.size(),m=waterStartTime.size();
        for (int i = 0; i < n; ++i) {
            land=min(land,landStartTime[i]+landDuration[i]);
        }
        for (int i = 0; i < m; ++i) {
            if (waterStartTime[i]>land){
                ans=min(ans,waterStartTime[i]+waterDuration[i]);
            }else{
                ans=min(ans,land+waterDuration[i]);
            }
            water=min(water,waterStartTime[i]+waterDuration[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (landStartTime[i]>water){
                ans=min(ans,landStartTime[i]+landDuration[i]);
            }else{
                ans=min(ans,water+landDuration[i]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}