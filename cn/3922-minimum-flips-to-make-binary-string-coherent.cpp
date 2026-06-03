#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), c0 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                c0++;
            } else {
                c1++;
            }
            if (i == 0 || i == n - 1) {
                if (s[i] == '0') {
                    c2++;
                }
            } else {
                if (s[i] == '1') {
                    c2++;
                }
            }
        }
        int ans = min({c0, c1, c2});
        if (c1 >= 1) {
            ans = min(ans, c1 - 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}