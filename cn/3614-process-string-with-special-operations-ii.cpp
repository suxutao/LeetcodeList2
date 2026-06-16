#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char processStr(string s, long long k) {
        long long sz = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                sz = max(sz - 1, 0ll);
            } else if (s[i] == '#') {
                sz <<= 1;
            } else if (s[i] != '%') {
                sz++;
            }
        }
        if (k >= sz)
            return '.';
        for (int i = s.size() - 1;; --i) {
            if (s[i] == '*') {
                sz++;
            } else if (s[i] == '#') {
                sz /= 2;
                if (k >= sz)
                    k -= sz;
            } else if (s[i] == '%') {
                k = sz - k - 1;
            } else {
                sz--;
                if (k == sz)
                    return s[i];
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}