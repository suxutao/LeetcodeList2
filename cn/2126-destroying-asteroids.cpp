#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
        long long m = mass;
        ranges::sort(asteroids);
        for (auto &i: asteroids) {
            if (m >= i) {
                m += i;
            } else {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}