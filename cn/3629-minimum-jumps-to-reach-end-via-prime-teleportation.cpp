#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
const int MX = 1'000'001;
vector<int> prime_factors[MX];

int init = [] {
    // 预处理每个数的质因子列表，思路同埃氏筛
    for (int i = 2; i < MX; i++) {
        if (prime_factors[i].empty()) { // i 是质数
            for (int j = i; j < MX; j += i) { // i 的倍数有质因子 i
                prime_factors[j].push_back(i);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            for (int p : prime_factors[nums[i]]) {
                groups[p].push_back(i); // 对于质数 p，可以跳到下标 i
            }
        }

        int ans = 0;
        vector<int8_t> vis(n);
        vis[0] = true;
        vector<int> q = {0};

        while (true) {
            auto tmp = q;
            q.clear();
            for (int i : tmp) {
                if (i == n - 1) {
                    return ans;
                }
                auto& idx = groups[nums[i]];
                idx.push_back(i + 1);
                if (i > 0) {
                    idx.push_back(i - 1);
                }
                for (int j : idx) { // 可以从 i 跳到 j
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push_back(j);
                    }
                }
                idx.clear(); // 避免重复访问下标列表
            }
            ans++;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}