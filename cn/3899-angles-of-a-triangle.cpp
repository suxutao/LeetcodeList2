#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        ranges::sort(sides);
        if (sides[0]+sides[1]<=sides[2])
            return {};
        double a=sides[0],b=sides[1],c=sides[2];
        double A= acos((b*b+c*c-a*a)/2/b/c)*180/acos(-1);
        double B= acos((a*a+c*c-b*b)/2/a/c)*180/acos(-1);
        return {A,B,180-A-B};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}