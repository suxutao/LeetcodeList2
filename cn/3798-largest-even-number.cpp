#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string largestEven(string s) {
        while (!s.empty()&&s.back()=='1')
            s.pop_back();
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}