#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    struct Node {
        Node* son[26]{};
        int min_len = INT_MAX; // 子树中的最短字符串的长度
        int best_index; // 子树中的最短字符串的下标
    };

    void clear(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->son[i]) {
                clear(node->son[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Node* root = new Node();
        for (int i = 0; i < wordsContainer.size(); i++) {
            auto& s = wordsContainer[i];
            int len = s.size();
            if (len < root->min_len) {
                root->min_len = len;
                root->best_index = i;
            }

            // 把 reverse(s) 插入字典树
            auto cur = root;
            for (int j = len - 1; j >= 0; j--) {
                int b = s[j] - 'a';
                if (cur->son[b] == nullptr) {
                    cur->son[b] = new Node();
                }
                cur = cur->son[b];
                // 维护 cur 子树中的最短字符串的长度及其下标
                // 由于我们是按照 i 从小到大的顺序遍历，字符串长度相同时不更新 best_index
                if (len < cur->min_len) {
                    cur->min_len = len;
                    cur->best_index = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (auto& s : wordsQuery) {
            auto cur = root;
            for (int j = s.size() - 1; j >= 0 && cur->son[s[j] - 'a']; j--) {
                cur = cur->son[s[j] - 'a'];
            }
            // 退出循环时，cur 即最长公共前缀（的对应节点），cur->best_index 是前缀为 cur 的最短字符串的下标
            ans.push_back(cur->best_index);
        }

        clear(root);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}