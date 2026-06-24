#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0,c=0;
        for (auto &i: moves){
            if (i=='U'){
                x++;
            }else if (i=='D'){
                x--;
            }else if (i=='L'){
                y++;
            }else if (i=='R'){
                y--;
            }else{
                c++;
            }
        }
        return c+abs(x)+abs(y);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}