#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool arr[101]{};
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        for (auto &item: nums){
            if (arr[item])
                ans.push_back(item);
            arr[item]=1;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}