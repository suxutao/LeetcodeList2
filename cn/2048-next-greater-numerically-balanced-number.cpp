#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool f(string&s){
        int arr[10]{};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]>='8')
                return false;
            arr[s[i]-'0']++;
        }
        for (int i = 0; i < 10; ++i) {
            if (arr[i]&&arr[i]!=i)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while (1){
            ++n;
            string s=to_string(n);
            if (f(s))
                return n;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}