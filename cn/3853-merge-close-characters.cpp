#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        string t;
        for (int i = 0; i < n; ++i) {
            bool b = true;
            for (int j = t.size() - 1; j >= max<int>(0, t.size() - k); --j) {
                if (t[j] == s[i]) {
                    b = false;
                    break;
                }
            }
            if (b)
                t.push_back(s[i]);
        }
        return t;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}