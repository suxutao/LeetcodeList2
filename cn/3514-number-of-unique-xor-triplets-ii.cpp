#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s,se;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                s.insert(nums[i]^nums[j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (auto &j: s){
                se.insert(nums[i]^j);
            }
        }
        return se.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}