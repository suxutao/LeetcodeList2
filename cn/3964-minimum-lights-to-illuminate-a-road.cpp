#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minLights(vector<int> &lights) {
        int n = lights.size(), ans = 0;
        vector<int> diff(n + 1);
        for (int i = 0; i < n; ++i) {
            if (lights[i]) {
                diff[max(0, i - lights[i])]++;
                diff[min(n - 1, i + lights[i]) + 1]--;
            }
        }
        int light = 0;
        for (int i = 0; i < n; ++i) {
            light += diff[i];
            if (light == 0) {
                ans++;
                light++;
                diff[min(n, i + 3)]--;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}