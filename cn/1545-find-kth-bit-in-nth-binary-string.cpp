#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char findKthBit(int n, int k) {
        int p=0;
        n=(1<<n)-1;
        while (n>1){
            if (k==(n+1)/2){
                return '1'-p;
            }else if (k>(n+1)/2){
                k=n-k+1;
                p=1-p;
            }
            n/=2;
        }
        return '0'+p;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}