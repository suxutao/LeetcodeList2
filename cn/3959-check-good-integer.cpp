#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkGoodInteger(int n) {
        int sq = 0, di = 0, t;
        while (n) {
            t = n % 10;
            sq += t * t;
            di += t;
            n /= 10;
        }
        return sq >= di + 50;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}