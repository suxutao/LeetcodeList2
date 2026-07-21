#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (abs(target[0]-start[0])+abs(target[1]-start[1]))%2==0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}