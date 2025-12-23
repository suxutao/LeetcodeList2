#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mirrorDistance(int n) {
        string s=to_string(n);
        ranges::reverse(s);
        return abs(n-stoi(s));
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}