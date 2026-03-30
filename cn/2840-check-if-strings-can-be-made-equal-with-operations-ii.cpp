#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        multiset<char>m1,m2;
        for (int i = 0; i < n; ++i) {
            if (i&1){
                m1.insert(s1[i]);
            }else{
                m2.insert(s1[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i&1){
                m1.extract(s2[i]);
            }else{
                m2.extract(s2[i]);
            }
        }
        return m1.empty()&&m2.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}