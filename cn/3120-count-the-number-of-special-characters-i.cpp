#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            bool small = 0, big = 0;
            for (auto j: word) {
                if (j == 'a' + i)
                    small = 1;
                if (j == 'A' + i)
                    big = 1;
            }
            if (small && big)
                ans++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}