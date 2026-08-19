#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int elevatorRequests(int n, vector<int> &requests) {
        int ans = requests[0], m = requests.size();
        for (int i = 1; i < m; ++i) {
            ans += abs(requests[i] - requests[i - 1]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    return 0;
}
