class Solution {
public:
    int compareVersion(string version1, string version2) {
        string curr1, curr2;
        bool b1 = false; bool b2 = false;
        int left = 0;
        int left2 = 0;
        while(true){
            if(!b1){
                if(version1[left] == '.' || left>=version1.size()){
                    b1 = true;
                } else {
                    curr1+=version1[left];
                }
                left++;
            }
            if(!b2){
                if(version2[left2] == '.' || left2>=version2.size()){
                    b2 = true;
                }else {
                    curr2+=version2[left2];
                }
                left2++;
            }
            if(b1 && b2){
                if (curr1.empty()) curr1 = "0";
                if (curr2.empty()) curr2 = "0";

                // strip leading zeros
                while (curr1.size() > 1 && curr1[0] == '0') curr1.erase(curr1.begin());
                while (curr2.size() > 1 && curr2[0] == '0') curr2.erase(curr2.begin());

                // compare
                if (curr1.size() > curr2.size()) return 1;
                if (curr1.size() < curr2.size()) return -1;

                if (curr1 > curr2) return 1;
                if (curr1 < curr2) return -1;

                curr1.clear(); curr2.clear();
                b1 = b2 = false;
            }
            if(left>=version1.size() && left2>=version2.size())break;
            if(left>=version1.size()){
                b1 = true;
            }
            if(left2>=version2.size()){
                b2 = true;
            }
        }
        if(!curr1.empty() || !curr2.empty()){
            if (curr1.empty()) curr1 = "0";
            if (curr2.empty()) curr2 = "0";

            while (curr1.size() > 1 && curr1[0] == '0') curr1.erase(curr1.begin());
            while (curr2.size() > 1 && curr2[0] == '0') curr2.erase(curr2.begin());

            if (curr1.size() > curr2.size()) return 1;
            if (curr1.size() < curr2.size()) return -1;

            if (curr1 > curr2) return 1;
            if (curr1 < curr2) return -1;
        }
        return 0;
    }
};