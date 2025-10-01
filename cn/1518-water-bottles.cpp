#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles,t=numBottles;
        while (t>=numExchange){
            ans+=t/numExchange;
            t=t/numExchange+t%numExchange;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}