#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts) {
        int ans = 0;
        if (startPos[0] <= homePos[0]) {
            for (int i = startPos[0] + 1; i <= homePos[0]; ++i) {
                ans += rowCosts[i];
            }
        } else {
            for (int i = homePos[0]; i < startPos[0]; ++i) {
                ans += rowCosts[i];
            }
        }
        if (startPos[1] <= homePos[1]) {
            for (int i = startPos[1] + 1; i <= homePos[1]; ++i) {
                ans += colCosts[i];
            }
        } else {
            for (int i = homePos[1]; i < startPos[1]; ++i) {
                ans += colCosts[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}