#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Robot {
    int w;
    int h;
    int s = 0;

    tuple<int, int, string> getState() {
        if (s < w) {
            return {s, 0, "East"};
        } else if (s < w + h - 1) {
            return {w - 1, s - w + 1, "North"};
        } else if (s < w * 2 + h - 2) {
            return {w * 2 + h - s - 3, h - 1, "West"};
        } else {
            return {0, (w + h) * 2 - s - 4, "South"};
        }
    }

public:
    Robot(int width, int height) : w(width), h(height) {}

    void step(int num) {
        // 由于机器人只能走外圈，那么走 (w+h-2)*2 步后会回到起点
        // 把 s 取模调整到 [1, (w+h-2)*2]，这样不需要特判 s == 0 时的方向
        s = (s + num - 1) % ((w + h - 2) * 2) + 1;
    }

    vector<int> getPos() {
        auto [x, y, _] = getState();
        return {x, y};
    }

    string getDir() {
        return get<2>(getState());
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    return 0;
}