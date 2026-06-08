#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long minEnergy(int n, int brightness, vector<vector<int>> &intervals) {
        ll x = ceil(brightness / 3.), len = 0;
        vector<vector<int>> v;
        ranges::sort(intervals);
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i][0], end = intervals[i][1];
            if (start > r) {
                len += r - l + 1;
                l = start, r = end;
            } else {
                r = max(r, end);
            }
        }
        len += r - l + 1;
        return x * len;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}