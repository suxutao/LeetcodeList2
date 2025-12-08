#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPrime(int x) {
        if (x == 1)
            return false;
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        if (!isPrime(num))
            return false;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            string s1 = s.substr(0, i), s2 = s.substr(i);
            int x1 = stoi(s1), x2 = stoi(s2);
            if (!isPrime(x1) || !isPrime(x2))
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}