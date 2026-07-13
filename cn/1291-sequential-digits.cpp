#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> v;
        for (int i = 0; i < 9; ++i) {
            for (int j = i + 1; j < 9; ++j) {
                int t = stoi(s.substr(i, j - i + 1));
                if (t >= low && t <= high)
                    v.push_back(t);
            }
        }
        ranges::sort(v);
        return v;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}