#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        for (int i = n; i >= 3; --i) {
            for (int j = 0; j < i - 1; ++j) {
                s[j] = (s[j] + s[j + 1] - '0' * 2) % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}