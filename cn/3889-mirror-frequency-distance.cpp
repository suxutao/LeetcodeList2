#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char f(char c) {
        if (isdigit(c)) {
            return '9' - c + '0';
        } else {
            return 'z' - c + 'a';
        }
    }

    int mirrorFrequency(string s) {
        int ans = 0;
        unordered_map<char, int> m;
        unordered_set<char> se;
        for (auto &i: s) {
            ++m[i];
        }
        for (auto &i: s) {
            if (!se.contains(i) && !se.contains(f(i))) {
                se.insert(i);
                ans += abs(m[i] - m[f(i)]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}