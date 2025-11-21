#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0)
            return false;
        if (n&(n-1))
            return false;
        return n&0b1010101010101010101010101010101;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}