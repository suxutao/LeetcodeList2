#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countCollisions(string directions) {
        int r=0,s=0,n=directions.size(),ans=0;
        for (int i = 0; i < n; ++i) {
            if (directions[i]=='L'){
                if (r){
                    ans+=r+1;
                    s=1;r=0;
                }else if (s){
                    ans++;
                }
            }else if (directions[i]=='S'){
                if (r){
                    ans+=r;
                    r=0;
                }
                s=1;
            }else{
                ++r;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}