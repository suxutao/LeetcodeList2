#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        return n ^ ((1 << bit_width((unsigned) n)) - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}