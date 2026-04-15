#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer==0)
            return "Green";
        else if (timer==30)
            return "Orange";
        else if (timer>30&&timer<=90)
            return "Red";
        else
            return "Invalid";
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}