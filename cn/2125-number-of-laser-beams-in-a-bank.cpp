#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        for (auto &item: bank){
            if (item.contains('1'))
                v.push_back(count(item.begin(), item.end(),'1'));
        }
        int n=v.size(),ans=0;
        for (int i = 0; i < n - 1; ++i) {
            ans+=v[i]*v[i+1];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}