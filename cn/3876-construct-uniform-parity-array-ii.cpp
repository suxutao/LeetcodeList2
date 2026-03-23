#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool f1(vector<int>&v){
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]&1){
                return false;
            }
        }
        return true;
    }
    bool f2(vector<int>&v){
        int ji=0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]%2==0){
                if (ji==0)
                    return false;
            }else if (ji==0){
                ji=v[i];
            }
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        ranges::sort(nums1);
        return f1(nums1)||f2(nums1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}