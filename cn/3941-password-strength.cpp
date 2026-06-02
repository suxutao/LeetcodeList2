#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        unordered_set<char>s;
        for (auto &i: password){
            if (s.contains(i))
                continue;
            s.insert(i);
            if (i>='a'&&i<='z'){
                ans++;
            }else if (i>='A'&&i<='Z'){
                ans+=2;
            }else if (i>='0'&&i<='9'){
                ans+=3;
            }else{
                ans+=5;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}