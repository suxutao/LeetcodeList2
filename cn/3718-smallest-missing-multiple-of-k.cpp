#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int qi=k;
        unordered_set<int>s;
        for(auto&i:nums){
            s.insert(i);
        }
        while (qi<=100){
            if (s.contains(qi))
                qi+=k;
            else
                break;
        }
        return qi;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}