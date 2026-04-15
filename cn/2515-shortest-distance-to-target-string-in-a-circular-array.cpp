#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int closestTarget(vector<string> &words, string target, int startIndex) {
        int ans = INT_MAX, n = words.size();
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                pos.push_back(i);
            }
        }
        if (pos.empty())
            return -1;
        for (auto &i: pos) {
            if (i <= startIndex)
                ans = min(ans, min(startIndex - i, i + n - startIndex));
            else
                ans = min(ans, min(i - startIndex, startIndex + n - i));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}