class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aliceArriveMonth = stoi(arriveAlice.substr(0, 2));
        int aliceArriveDay = stoi(arriveAlice.substr(3, 2));

        int aliceLeaveMonth = stoi(leaveAlice.substr(0, 2));
        int aliceLeaveDay = stoi(leaveAlice.substr(3, 2));

        int bobArriveMonth = stoi(arriveBob.substr(0, 2));
        int bobArriveDay = stoi(arriveBob.substr(3, 2));

        int bobLeaveMonth = stoi(leaveBob.substr(0, 2));
        int bobLeaveDay = stoi(leaveBob.substr(3, 2));

        if(aliceArriveMonth > bobArriveMonth || ((aliceArriveMonth == bobArriveMonth) && aliceArriveDay > bobArriveDay)){
            if(bobLeaveMonth < aliceArriveMonth || (bobLeaveMonth == aliceArriveMonth && bobLeaveDay < aliceArriveDay))return 0;
            int res = 0;
            for(int i = aliceArriveMonth; i <= aliceLeaveMonth && i <= bobLeaveMonth; i++){
                res+=months[i-1];
            }
            res-=aliceArriveDay-1;
            res-= months[min(bobLeaveMonth, aliceLeaveMonth)-1] - ((bobLeaveMonth == aliceLeaveMonth) ? min(bobLeaveDay, aliceLeaveDay) : (bobLeaveMonth <= aliceLeaveMonth ? bobLeaveDay : aliceLeaveDay));
            return res;
        }

        if(aliceLeaveMonth < bobArriveMonth || (aliceLeaveMonth == bobArriveMonth && aliceLeaveDay < bobArriveDay))return 0;
        int res = 0;
        // 3 - 5 --- 4-13
        // 3 - 15 --- 4-20
        for(int i = bobArriveMonth; i <= bobLeaveMonth && i <= aliceLeaveMonth; i++){
            res+=months[i-1]; //+ 31
        }
        res-=bobArriveDay-1; // -15
        res-= months[min(bobLeaveMonth, aliceLeaveMonth)-1] - ((bobLeaveMonth == aliceLeaveMonth) ? min(bobLeaveDay, aliceLeaveDay) : (bobLeaveMonth <= aliceLeaveMonth ? bobLeaveDay : aliceLeaveDay));
        return res;
    }
};
