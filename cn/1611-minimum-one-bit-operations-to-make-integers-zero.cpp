#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0)
            return 0;
        int k = bit_width((unsigned) n);
        return (1 << k) - 1 - minimumOneBitOperations(n - (1 << (k - 1)));
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}