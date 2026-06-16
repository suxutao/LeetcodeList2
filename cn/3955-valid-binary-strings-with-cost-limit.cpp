#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> vs;
        string s(n, '0');
        auto dfs = [&](this auto &&dfs, int pos, int price, bool one) -> void {
            if (pos == n) {
                vs.push_back(s);
                return;
            }
            if (price < pos || !one) {
                dfs(pos + 1, price, true);
            } else {
                dfs(pos + 1, price, true);
                s[pos] = '1';
                dfs(pos + 1, price - pos, false);
                s[pos] = '0';
            }
        };
        dfs(0, k, true);
        return vs;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}