#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>> &occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> v, ans;
        ranges::sort(occupiedIntervals);
        int l = occupiedIntervals[0][0], r = occupiedIntervals[0][1];
        for (int i = 1; i < occupiedIntervals.size(); ++i) {
            auto &o = occupiedIntervals[i];
            if (o[0] > r + 1) {
                v.push_back({l, r});
                l = o[0], r = o[1];
            } else {
                r = max(r, o[1]);
            }
        }
        v.push_back({l, r});
        for (auto &i: v) {
            if (i[1] < freeStart || i[0] > freeEnd) {
                ans.push_back(i);
            } else if (i[0] < freeStart && i[1] > freeEnd) {
                ans.push_back({i[0], freeStart - 1});
                ans.push_back({freeEnd + 1, i[1]});
            } else if (i[0] < freeStart) {
                ans.push_back({i[0], freeStart - 1});
            } else if (i[1] > freeEnd) {
                ans.push_back({freeEnd + 1, i[1]});
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}