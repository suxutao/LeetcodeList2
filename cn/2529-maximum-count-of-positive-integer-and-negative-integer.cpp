#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int find(vector<int>&v,int x){
        int l=0,r=v.size();
        while (l<r){
            int mid=(l+r)>>1;
            if (v[mid]<x){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        return max(find(nums,0),n-find(nums,1));
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}