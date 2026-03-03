#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char>se{'a','e','i','o','u'};
        while (!s.empty()&&se.contains(s.back()))
            s.pop_back();
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}