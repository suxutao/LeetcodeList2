#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>> &restrictions, vector<int> &diff) {
        vector<int> v(n), r(n, INT_MAX);
        for (auto &i: restrictions) {
            r[i[0]] = i[1];
        }
        for (int i = 0; i < n - 1; ++i) {
            v[i + 1] = min(v[i] + diff[i], r[i + 1]);
        }
        for (int i = n - 1; i > 1; --i) {
            v[i - 1] = min(v[i] + diff[i - 1], v[i - 1]);
        }
        return ranges::max(v);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}