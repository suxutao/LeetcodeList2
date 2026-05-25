#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), r = 0;
        vector<bool> b(n);
        b[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' && b[i]) {
                for (int j = max(i + minJump, r); j <= min(n - 1, i + maxJump); ++j) {
                    if (s[j] == '0') {
                        b[j] = 1;
                    }
                }
                r = min(n - 1, i + maxJump);
            }
        }
        return b[n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}