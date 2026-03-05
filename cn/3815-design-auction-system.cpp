#include "../../../stdc.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class AuctionSystem {
public:
    unordered_map<int,unordered_map<int,int>>price;
    unordered_map<int,priority_queue<array<int,2>>>q;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        price[userId][itemId]=bidAmount;
        q[itemId].push({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        price[userId][itemId]=newAmount;
        q[itemId].push({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        price[userId][itemId]=0;
    }
    
    int getHighestBidder(int itemId) {
        while (!q[itemId].empty()&&price[q[itemId].top()[1]][itemId]!=q[itemId].top()[0]){
            q[itemId].pop();
        }
        return q[itemId].empty()?-1:q[itemId].top()[1];
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    
    return 0;
}