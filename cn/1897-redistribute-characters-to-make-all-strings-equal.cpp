#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int arr['z'+1]{},n=words.size();
        for (auto &word: words){
            for (auto &i: word){
                ++arr[i];
            }
        }
        for (int i = 'a'; i <= 'z'; ++i) {
            if (arr[i]%n)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}