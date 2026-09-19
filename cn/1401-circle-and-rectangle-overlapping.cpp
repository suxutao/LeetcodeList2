#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dx=min(max(xCenter,x1),x2);
        int dy=min(max(yCenter,y1),y2);
        return (dx-xCenter)*(dx-xCenter)+(dy-yCenter)*(dy-yCenter)<=radius*radius;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}