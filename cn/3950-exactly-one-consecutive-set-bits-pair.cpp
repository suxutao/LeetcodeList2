#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int x = 3, cnt = 0;
        for (int i = 0; i < 20; ++i) {
            if ((x & n) == x) {
                cnt++;
                if (cnt > 1)
                    return false;
            }
            x <<= 1;
        }
        return cnt == 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}