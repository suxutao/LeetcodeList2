#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]].push_back(i);
        }
        int ans=m.size();
        for (auto&[_,v]:m) {
            for (int i = 1; i < v.size(); ++i) {
                if (v[i]!=v[i-1]+1) {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}