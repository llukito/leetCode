class Solution {
public:
    string solveEquation(string equation) {
        string curr = "";
        int leftSum = 0, leftX = 0;
        int index = -1;
        // Parse left side
        for (int i = 0; i < equation.length(); i++) {
            char ch = equation[i];
            if (ch == '+' || ch == '-' || ch == '=') {
                if (!curr.empty()) {
                    // x-term
                    if (curr.find('x') != string::npos) {
                        char sign = (curr[0] == '-') ? '-' : '+';
                        string num = "";
                        for (int j = (curr[0] == '+' || curr[0] == '-') ? 1 : 0; j < curr.size(); ++j) {
                            if (curr[j] == 'x') break;
                            num += curr[j];
                        }
                        int coeff = num.empty() ? 1 : stoi(num);
                        leftX += (sign == '+') ? coeff : -coeff;
                    }
                    // constant term
                    else {
                        char sign = '+';
                        if (curr[0] == '-') { sign = '-'; curr = curr.substr(1); }
                        else if (curr[0] == '+') { curr = curr.substr(1); }
                        if (!curr.empty()) {
                            int val = stoi(curr);
                            leftSum += (sign == '+') ? val : -val;
                        }
                    }
                }
                curr.clear();
                if (ch == '=') { index = i + 1; break; }
                curr += ch;
            } else {
                curr += ch;
            }
        }

        int rightSum = 0, rightX = 0;
        curr.clear();
        // Parse right side
        for (int i = index; i < equation.length(); i++) {
            char ch = equation[i];
            if (ch == '+' || ch == '-') {
                if (!curr.empty()) {
                    if (curr.find('x') != string::npos) {
                        char sign = (curr[0] == '-') ? '-' : '+';
                        string num = "";
                        for (int j = (curr[0] == '+' || curr[0] == '-') ? 1 : 0; j < curr.size(); ++j) {
                            if (curr[j] == 'x') break;
                            num += curr[j];
                        }
                        int coeff = num.empty() ? 1 : stoi(num);
                        rightX += (sign == '+') ? coeff : -coeff;
                    } else {
                        char sign = '+';
                        if (curr[0] == '-') { sign = '-'; curr = curr.substr(1); }
                        else if (curr[0] == '+') { curr = curr.substr(1); }
                        if (!curr.empty()) {
                            int val = stoi(curr);
                            rightSum += (sign == '+') ? val : -val;
                        }
                    }
                }
                curr.clear();
                curr += ch;
            } else {
                curr += ch;
            }
        }
        // Last term on right
        if (!curr.empty()) {
            if (curr.find('x') != string::npos) {
                char sign = (curr[0] == '-') ? '-' : '+';
                string num = "";
                for (int j = (curr[0] == '+' || curr[0] == '-') ? 1 : 0; j < curr.size(); ++j) {
                    if (curr[j] == 'x') break;
                    num += curr[j];
                }
                int coeff = num.empty() ? 1 : stoi(num);
                rightX += (sign == '+') ? coeff : -coeff;
            } else {
                char sign = '+';
                if (curr[0] == '-') { sign = '-'; curr = curr.substr(1); }
                else if (curr[0] == '+') { curr = curr.substr(1); }
                if (!curr.empty()) {
                    int val = stoi(curr);
                    rightSum += (sign == '+') ? val : -val;
                }
            }
        }
        int x = leftX - rightX;
        int num = rightSum - leftSum;
        if(x == 0){
            if(num == 0){
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        }
        int res = num/x;
        string rr = "x=";
        rr+=to_string(res);
        return rr;
    }
};
