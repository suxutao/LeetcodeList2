#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nearestDrone(vector<vector<int> > &drones, vector<int> &target) {
        int ans = -1, mx = INT_MAX,n=drones.size();
        for (int i = 0; i < n; ++i) {
            auto &d=drones[i];
            int dis = abs(d[0] - target[0]) + abs(d[1] - target[1]);
            if (dis <= d[2] && dis < mx) {
                mx = dis;
                ans = i;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
