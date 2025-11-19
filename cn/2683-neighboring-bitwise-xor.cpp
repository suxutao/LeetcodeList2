#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for (int i = 0; i < derived.size(); ++i) {
            ans^=derived[i];
        }
        return !ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}