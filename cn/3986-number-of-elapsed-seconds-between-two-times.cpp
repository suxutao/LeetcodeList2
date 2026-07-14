#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start=stoi(startTime.substr(0,2))*3600+stoi(startTime.substr(3,2))*60+stoi(startTime.substr(6,2));
        int end=stoi(endTime.substr(0,2))*3600+stoi(endTime.substr(3,2))*60+stoi(endTime.substr(6,2));
        return end-start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}