#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int zhi=-1;
        vector<int>ans(2,-1);
        for (auto &i: towers){
            if (abs(center[0]-i[0])+abs(center[1]-i[1])<=radius){
                if (i[2]>zhi){
                    zhi=i[2];
                    ans[0]=i[0];
                    ans[1]=i[1];
                }else if (i[2]==zhi){
                    if (i[0]<ans[0]){
                        ans[0]=i[0];
                        ans[1]=i[1];
                    }else if (i[0]==ans[0]&&i[1]<ans[1]){
                        ans[1]=i[1];
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}