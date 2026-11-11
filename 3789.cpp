class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long v1 = 1ll*cost1*need1 + 1ll*cost2*need2;
        long long v2 = 1ll*need1*costBoth + 1ll*max(need2-need1, 0)*cost2;
        long long v3 = 1ll*max(need1-need2, 0)*cost1 + 1ll*need2*costBoth;
        return min3(v1, v2, v3);
    }

    long long min3(long long v1, long long v2, long long v3){
        return min(min(v1, v2), v3);
    }
};
