#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    using ll = long long;

    long long maxRunTime(int n, vector<int> &batteries) {
        ranges::sort(batteries, greater<>());
        ll sum = accumulate(batteries.begin(), batteries.end(), 0ll);
        for (int i = 0; i < batteries.size(); ++i) {
            if (batteries[i] <= sum / n) {
                return sum / n;
            }
            sum -= batteries[i];
            n--;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}