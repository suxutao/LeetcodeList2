#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num*9<sum)
            return "";
        string s(num,'0');
        for (int i = 0; i < num; ++i) {
            if (sum>=9){
                sum-=9;
                s[i]='9';
            }else{
                s[i]=sum+'0';
                break;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}