#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size(),ans=0,mn,pre=0;
        vector<int>suf(n+1);
        for (int i = n - 1; i >= 0; --i) {
            suf[i]=suf[i+1]+(customers[i]=='Y');
        }
        mn=suf[0];
        for (int i = 0; i < n; ++i) {
            pre+=customers[i]=='N';
            if (pre+suf[i+1]<mn){
                mn=pre+suf[i+1];
                ans=i+1;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}