#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bitset<8> f(int x) {
        bitset<8> b;
        for (int i = 0; i < 8; ++i) {
            if (x & 1)
                b[i] = 1;
            x >>= 1;
        }
        return b;
    }

    bool isPalindromic(string s) {
        int n = s.size();
        if (n & 1) {
            bitset<8> b = f(s[n / 2]);
            for (int i = 0; i < 4; ++i) {
                if (b[i] != b[7 - i])
                    return false;
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            bitset<8> b1 = f(s[i]), b2 = f(s[n - 1 - i]);
            for (int j = 0; j < 8; ++j) {
                if (b1[j] != b2[7 - j])
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
