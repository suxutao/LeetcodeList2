#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxDistinct(string s) {
        return unordered_set<char>(s.begin(),s.end()).size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}