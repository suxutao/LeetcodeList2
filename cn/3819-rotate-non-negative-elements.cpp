#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(nums),pos,ele;
        for (int i = 0; i < n; ++i) {
            if (nums[i]>=0){
                pos.push_back(i);
                ele.push_back(nums[i]);
            }
        }
        int np=pos.size();
        for (int i = 0; i < pos.size(); ++i) {
            ans[pos[i]]=ele[(i+k)%np];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}