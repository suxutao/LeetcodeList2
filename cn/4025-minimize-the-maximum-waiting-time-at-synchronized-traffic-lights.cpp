#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPenalty(int period, vector<int> &lights, vector<int> &arrivalTime) {
        int mx = ranges::max(lights), ans = 0;
        for (auto time: arrivalTime) {
            time %= period;
            if (time >= mx)
                ans = max(ans, period - time);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
