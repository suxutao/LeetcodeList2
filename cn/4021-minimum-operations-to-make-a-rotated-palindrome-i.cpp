#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int sum = i;
            for (int j = 0; j < n / 2; ++j) {
                int mx = max(s[j], s[n - j - 1]);
                int mn = min(s[j], s[n - j - 1]);
                sum += min(mx - mn, mn + 26 - mx);
            }
            ans = min(ans, sum);
            s.push_back(s[0]);
            s.erase(s.begin());
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
