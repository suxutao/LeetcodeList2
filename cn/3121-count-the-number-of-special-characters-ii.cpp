#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool arr['z' + 1]{}, can['z' + 1]{};
        unordered_set<char> s;
        for (auto i: word) {
            arr[i] = 1;
            if (islower(i)) {
                if (arr[i - 32]) {
                    s.erase(i);
                    can[i] = 1;
                }
            } else {
                if (arr[i + 32] && !can[i + 32]) {
                    s.insert(i + 32);
                }
            }
        }
        return s.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}