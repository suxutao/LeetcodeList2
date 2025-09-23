#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int find_first(vector<int>& nums, int target){
        int l=0,r=nums.size();
        while (l<r){
            int mid=(l+r)>>1;
            if (nums[mid]>=target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l= find_first(nums,target);
        if (l==nums.size()||nums[l]!=target)
            return {-1,-1};
        return {l, find_first(nums,target+1)-1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}