class AuctionSystem {
public:

    unordered_map<int, set<pair<int,int>>> itemToUsers;
    unordered_map<int, unordered_map<int, int>> userToItems;

    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(userToItems.count(userId) && userToItems[userId].count(itemId)){
            removeBid(userId, itemId);
        }
        userToItems[userId][itemId] = bidAmount;
        itemToUsers[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        itemToUsers[itemId].erase({userToItems[userId][itemId], userId});
        userToItems[userId].erase(itemId);
        if(itemToUsers[itemId].size() == 0){
            itemToUsers.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        return itemToUsers.count(itemId) ? (itemToUsers[itemId].rbegin())->second : -1;
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
