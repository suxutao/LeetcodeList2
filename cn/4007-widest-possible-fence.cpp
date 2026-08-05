#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n=planks.size(),ans=1;
        unordered_map<int,int>cnt,cnt2;
        for (int i = 0; i < n; ++i) {
            cnt[planks[i]]++;
        }
        for (auto &[val,c]: cnt){
            cnt2[val]+=c;
            cnt2[val*2]+=c/2;
            for (auto &[val2,c2]: cnt){
                if (val2<=val)
                    continue;
                cnt2[val+val2]+=min(c,c2);
            }
        }
        for (auto &[val,c]: cnt2){
            ans=max(ans,c);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}