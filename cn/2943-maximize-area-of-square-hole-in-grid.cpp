#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int mx1=1,mx2=1,pre=1;
        ranges::sort(hBars);
        ranges::sort(vBars);
        for (int i = 1; i < hBars.size(); ++i) {
            if (hBars[i]==hBars[i-1]+1){
                pre++;
                mx1=max(mx1,pre);
            }else{
                pre=1;
            }
        }
        pre=1;
        for (int i = 1; i < vBars.size(); ++i) {
            if (vBars[i]==vBars[i-1]+1){
                pre++;
                mx2=max(mx2,pre);
            }else{
                pre=1;
            }
        }
        int mx=min(mx1,mx2)+1;
        return mx*mx;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}