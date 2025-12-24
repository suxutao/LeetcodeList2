#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(), apple.end(),0),s=0;
        ranges::sort(capacity,greater<>());
        for (int i = 0; i < capacity.size(); ++i) {
            s+=capacity[i];
            if (sum<=s)
                return i+1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}