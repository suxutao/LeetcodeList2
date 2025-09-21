#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size();
        while (l<r){
            int mid=(l+r)>>1;
            if (nums[mid]==target)
                return mid;
            else if (nums[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}