#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(), p = 0;
        string ans;
        vector<string> vs(numRows);
        while (p < n) {
            for (int i = 0; i < numRows && p < n; ++i, ++p) {
                vs[i].push_back(s[p]);
            }
            for (int i = numRows - 2; i > 0 && p < n; --i, ++p) {
                vs[i].push_back(s[p]);
            }
        }
        for (auto &item: vs)
            ans+=item;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}