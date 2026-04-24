#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size(),l=0,r=0,m=0;
        for (int i = 0; i < n; ++i) {
            if (moves[i]=='L'){
                l++;
            }else if (moves[i]=='R'){
                r++;
            }else{
                m++;
            }
        }
        return max(l+m-r,r+m-l);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}