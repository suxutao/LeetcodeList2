#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> scoreValidator(vector<string> &events) {
        vector<int> ans{0, 0};
        for (auto &i: events) {
            if (i.size() == 1) {
                if (i[0] == 'W') {
                    ans[1]++;
                    if (ans[1] == 10)
                        break;
                } else {
                    ans[0] += i[0] - '0';
                }
            } else {
                ans[0]++;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}