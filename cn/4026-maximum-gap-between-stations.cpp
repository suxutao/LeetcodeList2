#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumGap(string skill, string station) {
        int m = skill.size(), n = station.size();
        int pl = 0, pr = n - 1, ans = 0;
        vector<int> pre(m);
        for (int i = 0; i < m; ++i) {
            while (station[pl] != skill[i]) {
                pl++;
            }
            pre[i] = pl++;
        }
        for (int i = m - 1; i > 0; --i) {
            while (station[pr] != skill[i]) {
                pr--;
            }
            ans = max(ans, pr - pre[i - 1]);
            pr--;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
