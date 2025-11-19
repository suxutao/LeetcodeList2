#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minChanges(int n, int k) {
        if ((n|k)!=n)
            return -1;
        return popcount((unsigned)n^k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}