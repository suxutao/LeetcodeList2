#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestInteger(int n, int s) {
        if (n * 9 < s)
            return -1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans *= 10;
            if (s > 9) {
                ans += 9;
                s -= 9;
            } else {
                ans += s;
                s = 0;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}